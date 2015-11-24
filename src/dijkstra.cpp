#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

struct Edge {
  int target;
  int weight;
};
struct Vertex {
  vector<Edge> neighbours;
};
struct FVertex {
  double f;
  int target;
};
void dijkstra(const vector<Vertex> &network, int startnode) {
  auto comp = [](FVertex f1, FVertex f2) { return f1.f > f2.f; };
  priority_queue<FVertex, vector<FVertex>, decltype(comp)> q(comp);

  set<int> visited;
  q.push({0, startnode});

  while (!q.empty()) {
    FVertex f = q.top();
    q.pop();

    if (visited.find(f.target) != visited.end())
      continue;

    visited.insert(f.target);

    cout << "The shortest path to " << f.target << " is " << f.f
         << " units long" << endl;

    const vector<Edge> &neighbours = network[f.target].neighbours;
    for (int i = 0; i < neighbours.size(); ++i) {
      FVertex nextf;
      nextf.f = f.f + neighbours[i].weight;
      nextf.target = neighbours[i].target;
      q.push(nextf);
    }
  }
};

int main() {
  vector<Vertex> verts(4);

  verts[0].neighbours = {{1, 333}, {2, 1000}, {3, 1337}};
  verts[1].neighbours = {{0, 1}, {2, 333}};
  verts[2].neighbours = {{0, 1000}, {1, 1}};
  verts[3].neighbours = {};

  dijkstra(verts, 0 /*startnode*/);
}