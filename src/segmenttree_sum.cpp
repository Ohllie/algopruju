#include <iostream>
#include <cassert>
#include <vector>

unsigned long upper_power_of_two(unsigned long v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

// Segmenttipuu summa-operaatiolle
// * olettaa ei-negatiiviset arvot bucketeihin => monotonisuus => get_index()
// * ctoriin buckettien lkm.

class BinarySumTree
{
private:
	std::vector<size_t> m_tree;
	size_t m_sindex;
public:
	BinarySumTree(size_t n)
		: m_tree()
		, m_sindex(0)
	{
		resize(n);
	}

	void resize(size_t n)
	{
		std::vector<size_t> lastrow(m_tree.begin()+m_sindex, m_tree.end());
		assert(n > 0);
		m_sindex = upper_power_of_two(n)-1;
		m_tree.assign(m_sindex*2+1, 0);
		for(size_t i = 0; i < lastrow.size() && i < n; ++i)
			increment(i, lastrow[i]);
	}

	void increment(size_t index, int amount = 1)
	{
		assert(index < m_tree.size() - m_sindex);
		index += m_sindex;

		if(amount < 0 && m_tree[index] < unsigned(-amount))
			amount = -m_tree[index];
		while(index != 0)
		{
			m_tree[index] += amount;
			index = (index-1)>>1;
		}
		m_tree[0] += amount;
	}
	void set(size_t index, unsigned value)
	{
		assert(index < m_tree.size() - m_sindex);
		increment(index, value-m_tree[index+m_sindex]);
	}
	void zero(size_t index)
	{
		set(index, 0);
	}
	size_t get_before(size_t index) const
	{
		assert(index < m_tree.size() - m_sindex);
		int ret = 0;
		index += m_sindex;
		while(index != 0)
		{
			if(!(index & 1))
				ret += m_tree[index-1];
			index = (index-1)>>1;
		}
		return ret;
	}
	size_t get_after(size_t index) const
	{
		return get_before(index) + m_tree[index + m_sindex];
	}
	size_t get(size_t index) const
	{
		assert(index < m_tree.size() - m_sindex);
		return m_tree[index + m_sindex];
	}
	size_t get_total() const
	{
		return m_tree[0];
	}
	size_t get_index(size_t value) const
	{
		size_t index = 0;
		assert(value < get_total());
		
		for(;;)
		{
			size_t left = 2*index+1;
			size_t right = 2*index+2;
			if(left >= m_tree.size())
				break;
			if(value < m_tree[left])
				index = left;
			else
			{
				value -= m_tree[left];
				index = right;
			}
		}
		return index - m_sindex;
	}
	size_t get_range(size_t begin, size_t end) const
	{
		assert(begin <= end);
		return get_after(end) - get_before(begin);
	}
};


int main()
{
	BinarySumTree tree(8);

	tree.increment(0,10);
	tree.increment(1,10);
	tree.increment(2,10);
	tree.increment(7,1);

	assert(tree.get_before(0) == 0);
	assert(tree.get_after(0) == 10);
	assert(tree.get_before(1) == 10);
	assert(tree.get_before(2) == 20);
	assert(tree.get_before(3) == 30);
	assert(tree.get_before(7) == 30);

	assert(tree.get_index(0) == 0);
	assert(tree.get_index(1) == 0);
	assert(tree.get_index(9) == 0);
	assert(tree.get_index(10) == 1);
	assert(tree.get_index(29) == 2);
	assert(tree.get_index(30) == 7);
	
	assert(tree.get_range(0,7) == 31);
	assert(tree.get_range(0,0) == 10);
	assert(tree.get_range(1,1) == 10);
	assert(tree.get_range(0,6) == 30);
	assert(tree.get_range(3,6) == 0);
}
