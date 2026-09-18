#include <iostream>
#include <vector>
using namespace std;
//No need to include anything
int main() {
    pair <int, int> p1 = {1, 2};
    cout<< p1.first<< " " << p1.second;
    pair <string, int> p2 = {"abc", 5};
    //Still use .first and .second

    //pair of pairs
    pair <int, pair <int, char> > p3 = {1, {1, 'c'}};
    cout<< p3.second.first; //1
    cout<< p3.second.second; //c
    //Cant directly use .second inside a pair

    //pair is considered as a new datatype
    vector <pair <int, int>> vec = {{1, 2}, {3, 4}};
    vec.push_back({5, 6});
    // or use
    vec.emplace_back(7, 8);

    for (pair <int, int> p : vec) {
        cout<< p.first << " " << p.second << " ";
    }
    return 0;
}