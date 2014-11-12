#include "dfs.hh"

int main(){
    int n = 9;
    vector<Vertex> vertices(9);

    vector<int> edges = {0, 1, 0, 2, 1, 2, 2, 3, 3, 4, 7, 8}; // (0,1), (0,2), (1,2)
    for(int i = 0; i < edges.size(); i += 2){
        int v1 = edges[i];
        int v2 = edges[i+1];
        vertices[v1].neighbors.push_back(v2);
        vertices[v2].neighbors.push_back(v1);
    }
    cout << "DFS" << endl;
    dfs(vertices,0);
    cout << "BFS" << endl;
    bfs(vertices,0);
}
