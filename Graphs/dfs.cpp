#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph {
    int V;
    list <int> *l;

    public:
    Graph (int vertices) {
        V = vertices;
        l = new list <int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void depthFirstSearch(int u, vector <int> &vis) {
        cout<<u<<" ";
        vis[u] = 1;

        for (int v : l[u]) {
            if (vis[v] == 0) {
                depthFirstSearch(v, vis);
            }
        }

    }
    
};

int main() {
    Graph g(5);
    vector <int> visited(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.depthFirstSearch(0, visited);
    return 0;
}