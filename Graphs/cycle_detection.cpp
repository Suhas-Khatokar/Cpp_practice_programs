#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;
    list <int> *l;

    public:
    Graph(int vertices) {
        V = vertices;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool cycle_det_dfs(int src, vector <int> &vis, int parent) {
        vis[src] = 1;

        for (int u : l[src]) {
            if (vis[u] == 0) {
                if (cycle_det_dfs(u, vis, src)) return true;
                 // If cycle found deeper, return true to src recursively 
            } else if (u != parent) return true; 
              // u is already visited and isn't my parent -> CYCLE
            
        }

        return false;
    }
    /*
    Is u visited?
          |
        ┌─┴─┐
        NO   YES
        |     |
        ↓     ↓
        visit   u != parent?
                |
            ┌─┴─┐
            NO   YES
            |     |
            ignore CYCLE
    */
};

int main() {
    vector <int> vis(5);
    Graph g(5);
    g.addEdge(0, 1);
    //g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    cout<<g.cycle_det_dfs(0, vis, -1);
    return 0;
}