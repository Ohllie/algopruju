#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Vertex {
public:
  vector<int> neighbors;
};

void dfs(vector<Vertex> &vertices, int node) {
  deque<int> stack;
  vector<bool> visited(vertices.size(), false);
  stack.push_back(node);
  while (stack.size() != 0) {
    int v = stack.back();
    stack.pop_back();
    if (visited[v])
      continue;
    visited[v] = true;

    cout << v << endl; // Do stuff here

    for (int u : vertices[v].neighbors) {
      stack.push_back(u);
    }
  }
}

void bfs(vector<Vertex> &vertices, int node) {
  deque<int> stack;
  vector<bool> visited(vertices.size(), false);
  stack.push_back(node);
  while (stack.size() != 0) {
    int v = stack.front();
    stack.pop_front();
    if (visited[v])
      continue;
    visited[v] = true;

    cout << v << endl; // Do stuff here

    for (int u : vertices[v].neighbors) {
      stack.push_back(u);
    }
  }
}
