#include <algorithm>

const int MIN_N = 0;
const int MAX_N = 1<<30;
struct node {
  int value = 0;
  node *left = 0;
  node *right = 0;
  node *getLeft() {
    if (!left) left = new node();
    return left;
  }
  node *getRight() {
    if (!right) right = new node();
    return right;
  }
};
node *root = new node();
void updateRange(int left, int right, int value, node *current = 0, int nodeleft = MIN_N, int noderight = MAX_N) {
  if (current == 0)current = root;
  if (left > noderight || right < nodeleft)return;
  if (left == nodeleft && right == noderight) {
    current->value += value;
    return;
  }
  int nodemid = nodeleft + (noderight - nodeleft + 1)/2;
  updateRange(left, std::min(right, nodemid-1), value, current->getLeft(), nodeleft, nodemid-1);
  updateRange(std::max(nodemid, left), right, value, current->getRight(), nodemid, noderight);
}
int querySum(int index,  node *current = 0, int nodeleft = MIN_N, int noderight = MAX_N) {
  if (current == 0) current = root;
  if (index < nodeleft || index > noderight)return 0;
  if (index == nodeleft && index == noderight)return current->value;
  int nodemid = nodeleft + (noderight - nodeleft + 1)/2;
  if (index < nodemid && current->left)
    return current->value + querySum(index, current->getLeft(), nodeleft, nodemid-1);
  if (current->right)
    return current->value + querySum(index, current->getRight(), nodemid, noderight);
  return current->value;
}

