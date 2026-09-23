#include <iostream>
#include <vector>
#include <list> //A doubly LL internally
using namespace std;

//Graph -> Includes a dynamic ARRAY which STORES LISTS where each LIST stores the NEIGHBOURS
//of a vertex of that index of that array

//new int[5] means you create a DYNAMIC ARRAY of size 5 
//new data_struc[num] creates a DYNAMIC ARRAY of size num with each ele as that data struc

class Graph {
    int V; //No of vertices in a graph
    list <int> *l; //This is a pointer to a list

    public:
    Graph (int vertices) {
        V = vertices;
        l = new list<int> [V]; // Create a dynamic array of V lists
                               // Each element of this array is a list<int>
                               //l[x] → list storing neighbours of vertex x
                               // l → points to the first list / starting point
    }

    void addEdge(int u, int v) {

        l[u].push_back(v); // In the list associated with vertex u,
                        // store v as its neighbour

        l[v].push_back(u); // In the list associated with vertex v,
                        // store u as its neighbour
    }

    void printAdjList() {
        for (int i=0; i<V; i++) {
            cout<< i << " : ";
            for (int neighbourgs : l[i]) {
                cout<<neighbourgs<<" ";
            }
            cout<<endl;
        }
    }

};


int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(1, 3);

    g.printAdjList();
    /*
    0 : 1 
    1 : 0 2 3 
    2 : 1 3 4 
    3 : 2 1 
    4 : 2 
    */
    /*
        0
        |
        1
       / \
      2---3
      |
      4
    */
    return 0;
}
