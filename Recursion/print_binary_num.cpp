#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
vector <vector <int>> ans;
void printBinary(int num, int i) {
    if (i==num) {
        ans.push_back(v);
        return;
    }
    v.push_back(0);
    printBinary(num, i+1);
    v.pop_back();
    v.push_back(1);
    printBinary(num, i+1);
    v.pop_back();

}

int main() {
    printBinary(4, 0);
    for (int i=0; i<ans.size(); i++) {
        for (int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}