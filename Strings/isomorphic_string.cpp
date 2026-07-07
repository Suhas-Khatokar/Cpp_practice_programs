#include<iostream>
#include <vector>
using namespace std;

bool isIsomorphic(string s, string t) {
    bool isIso = true;
    int n = s.length();
    
    vector <vector<char>> letters(n, vector<char>(2));

    for (int i=0; i<n; i++) {
        letters[i][0] = s[i];
        letters[i][1] = t[i];
    }

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (letters[i][0] == letters[j][0] && letters[i] != letters[j]) isIso = false;
            if (letters [i][1] == letters[j][1] && letters[i] != letters[j]) isIso = false;
        }
    }

    return isIso;

}

int main() {
    bool ans = isIsomorphic("aba", "xyx");
    cout<<ans;
    return 0;
}