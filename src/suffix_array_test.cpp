#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <string>
#include <cassert>
#include "suffix_array.hh"

vector<int> get_suffix_array_naive(string s) {
  vector<string> suffixes;
  for (int i = 0; i < s.size(); i++)
    suffixes.push_back(s.substr(i));
  sort(suffixes.begin(), suffixes.end());
  vector<int> SA(s.size());
  for (int i = 0; i < s.size(); i++) {
    SA[i] = s.size() - suffixes[i].size();
  }
  return SA;
}

int main() {
  string s = 
"abcabcabcabcabcabcabcabcabcabczzzjsjksdfkjasdfhkajsdfhkabcabckajs"
             "dhfkajsdhfkajshdf";
  vector<int> svec(s.begin(), s.end());
  assert(get_suffix_array(svec) == get_suffix_array_naive(s));
  vector<int> empty;
  assert(get_suffix_array(empty).size() == 0);

  string x = "";
  srand(time(NULL));
  for (int i = 0; i < 1000; i++) {
    x += (char)(rand() % 10 + 65);
    vector<int> xvec(x.begin(), x.end());
    assert(get_suffix_array(xvec) == get_suffix_array_naive(x));
  }

  cout << "All tests OK" << endl;
}
