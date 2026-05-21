#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFSUtil(int v, vector<bool>& vis) {
        vis[v] = true;
        cout << v << " ";
        for (int neighbor : adj[v]) {
            if (!vis[neighbor]) {
                DFSUtil(neighbor, vis);
            }
        }
    }

    void DFS(int start) {
        vector<bool> vis(V, false);
        cout << "DFS starting with vertex: " << start << "\n";
        DFSUtil(start, vis);
        cout << "\n";
    }

    void printGraph() {
        cout << "Graph\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int j : adj[i]) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.printGraph();
    g.DFS(0);
    return 0;
}
