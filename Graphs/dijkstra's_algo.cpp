#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Dijkstra's algo -> Shortest dist between two vertices (Directed + weighted graph)
//Class is of an edge where you store next vertex and weight and the graph is a 2D vec
class Edge {
    public:
    int v;
    int wt;
    Edge(int x, int y) {
        v = x;
        wt = y;
    }
};

void dijkstra(vector <vector <Edge>> g, int src, int V) {
    vector <int> dist(V, INT_MAX); //A vector which stores shortest dist from source to every node

    //For max heap, no need to write greater
    //Creates a min heap (first num of pair will be sorted in ascending order)
    priority_queue <pair <int, int>, vector <pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;                                                          
        pq.pop();

        for (Edge e : g[u]) {
            if (dist[e.v] > dist[u] + e.wt) {
                dist[e.v] = dist[u] + e.wt;
                pq.push({dist[e.v], e.v});
            }
        }
    }

    for (int i=0; i<V; i++) {
        cout<<dist[i]<<" ";
    }

}

int main() {
    int V = 6;
    vector<vector<Edge>> g(V);
    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(2, 1));
    g[1].push_back(Edge(3, 7));

    g[2].push_back(Edge(4, 3));
    g[3].push_back(Edge(5, 1));

    g[4].push_back(Edge(3, 2));
    g[4].push_back(Edge(5, 5));

    dijkstra(g, 0, V);

    return 0;
}