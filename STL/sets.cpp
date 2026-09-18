#include <iostream>
#include <set>
using namespace std;

int main() {
    //Set stores val in sorted order and only stores unique values
    set <int> s;
    s.insert(5);
    s.insert(2);
    s.insert(1);
    s.insert(3);
    s.insert(4);
    
    s.insert(1);
    s.insert(2);
    //Still set is 1 2 3 4 5 AND size is 5
    cout<<s.size();
    for (auto val : s) {
        cout<<val<<" ";
    }
    return 0;
}