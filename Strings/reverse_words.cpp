#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    stack <char> st;
//  "hello    world"
    string ans;
    string substring;
    for (int i=0; i<s.length(); i++) {
        st.push(s[i]);
    }
    while (!st.empty()) {
        if (st.top() != ' ') {
            substring.push_back(st.top());
        } else {
            reverse(substring.begin(), substring.end());
            if (!ans.empty()) ans.push_back(' ');
            ans += substring;
            substring = "";
        }
        st.pop();
    }
    reverse(substring.begin(), substring.end());
    ans += substring;
    return ans;
}

int main() {
    string s = "hello  world         today";
    string ans = reverseWords(s);
    cout<<ans;
    return 0;
}