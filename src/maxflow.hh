#include <queue>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

struct Mat
{
    Mat(int s) : size(s) { dat.resize(size*size, 0); }
    int& operator()(int i, int j) { return dat[j+i*size]; }
    vector<int> dat;
    int size;
};

bool bfs(Mat g, int source, int sink, vector<int> &parent)
{
    queue<int> q;
    vector<bool> visited;
    visited.resize(g.size, false);
    visited[source] = true;
    q.push(source);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < g.size; ++v) {
            if (!visited[v] && g(u,v) > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[sink];
}

int maxflow(Mat g, int source, int sink, Mat &result)
{
    Mat residual = g;
    vector<int> parent;
    for (int i = 0; i < g.size; ++i) {
        parent.push_back(-1);
    }
    
    int max_flow = 0;
    while (bfs(residual, source, sink, parent)) {
        int path_flow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, residual(u,v));
        }
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residual(u,v) -= path_flow;
            residual(v,u) += path_flow;
        }
        max_flow += path_flow;
    }

    for (int i = 0; i < g.size; ++i) {
        for (int j = 0; j < g.size; ++j) {
            result(i,j) = max(g(i,j) - residual(i,j), 0);
        }
    }

    // To find mincut: Copy bfs-routine here and check which vertices
    // are visited. They form the part which contains source.

    return max_flow;
}
