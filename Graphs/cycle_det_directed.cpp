#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

class Graph {
    int V;
    list <int> *l;
public:
    Graph(int vertices) {
        V = vertices;
        l = new list <int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v); // Creates an edge for a directed graph u->v
    }

    bool dfs(int u, vector <int> &vis, vector <int> &path) {
        vis[u] = 1;
        path[u] = 1;
        for (int x : l[u]) {
            if (vis[x] == 0) {
                if(dfs(x, vis, path)) return true;
            }
            else if (path[x] == 1) {
                return true;
            }
        }
        path[u] = 0;

        return false;
    }

    bool isCycle() {
        vector <int> vis(V);
        vector <int> path(V);

        for (int i=0; i<V; i++) {
            if (vis[i] == 0) {
                if(dfs(i, vis, path)) return true;
            }
        }

        return false;
    }
};

int main() {
    Graph g(4);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    cout<<g.isCycle();

    return 0;
}
