#include <vector>

using namespace std;

int nextPowerOfTwo(int x) {
  int power = 0;
  while (x != 0) {
    x /= 2;
    power++;
  }
  return 1 << power;
}

void segTreeSet(vector<int> &tree, int (*f)(int, int), int pos, int value) {
  pos += tree.size() / 2;
  tree[pos] = value;
  for (pos /= 2; pos >= 1; pos /= 2) {
    tree[pos] = f(tree[2 * pos], tree[2 * pos + 1]);
  }
}

int segTreeGet(vector<int> &tree, int (*f)(int, int), int i, int j) {
  i += tree.size() / 2;
  j += tree.size() / 2;
  int q = tree[i]; // q = tree[i] for min- and max-tree, q = zero for sum-tree
  // In general q should be initialized to a neutral element of the operation f
  while (i <= j) {
    if (i % 2 == 1)
      q = f(q, tree[i++]);
    if (j % 2 == 0)
      q = f(q, tree[j--]);
    i /= 2;
    j /= 2;
  }
  return q;
}

int main() { vector<int> exampleTree(nextPowerOfTwo(number of elements) * 2); }
