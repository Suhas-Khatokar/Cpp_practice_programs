#include <iostream>
#include <vector>
#include <queue>
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

    void breadthFirstTraversal() {
        queue <int> q;
        vector <int> checker(V);
        q.push(0);
        checker[0] = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";

            for (int v : l[curr]) {
                if (checker[v] == 0) {
                    checker[v] = 1;
                    q.push(v);
                }
            }
        }
    }
};

int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);

    g.breadthFirstTraversal();

    return 0;
}