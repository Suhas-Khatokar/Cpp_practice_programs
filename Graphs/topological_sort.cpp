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

    //Topological sort only works for directed graph which does not have a cycle
    // Topological Sort: u->v => u comes before v. DFS + push node after its neighbours.
    /*
    5->0
    4->0
    5->2
    4->1
    2->3
    3->1

    5 4 2 3 1
    or
    5 4 0 2 3 1
    or
    4 5 0 2 3 1
    and so on...

    for every u->v, u must come before v
    */
    void dfs(vector <int> &vis, int u, stack <int> &st) {
        vis[u] = 1;
        
        for (int x : l[u]) {
            if (vis[x] == 0) dfs(vis, x, st);
        }
        
        st.push(u);

    }

    void topoSort(vector <int> &vis) {
        stack <int> st;
        for (int i=0; i<V; i++) {
            if (vis[i] == 0) dfs(vis, i, st);
        }

        while (!st.empty()) {
            cout<<st.top()<<" ";
            st.pop();
        }
    }

};

int main() {
    Graph g(6);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(5, 2);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    vector <int> vis(6);
    g.topoSort(vis);
    return 0;
}