#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    //In map, the keys are unique and are in SORTED ORDER BY ITSELF
    map <string, int> m;
    m["Orange"] = 5;
    m["Apple"] = 6;
    m["Banana"] = 7;
    m.insert({"Mango", 2});
    m.emplace("Papaya", 1);

    m.erase("Papaya");
    if (m.find("Papaya") != m.end()) cout<<"Found"<<endl;
    else cout<<"Not found"<<endl;
    cout<<m.size()<<endl;
    for (auto p : m) {
        cout<<p.first<<" "<<p.second<<endl;
    }
    unordered_map <int, int> um;

    //In a multimap, keys can be duplicate and only emplace func works
    //map and unordered_map are the same excpet NOT IN SORTEDC ORDER
    return 0;
}