#include<iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    string prefix;
    int n = strs.size();
    bool same_ch = true;
    
    for (int j=0; j<strs[0].size(); j++) {
        char x = strs[0][j];
        for (int k=1; k<n; k++) {
            if (strs[k][j] != x) same_ch = false;
        }
        if (same_ch == true) prefix += x;
    }
    
    return prefix;
}

int main() {
    int n;
    cout<<"Enter the no of strings";
    cin>>n;
    cout<<"Enter the strings: ";
    vector <string> strs;

    for (int i=0; i<n; i++) {
        string x;
        cin>>x;
        strs.push_back(x);
    }

    cout<<"Longest common prefix: "<<longestCommonPrefix(strs);
    
    return 0;
}