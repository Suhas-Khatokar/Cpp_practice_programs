#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack <char> st;
    int n = s.size();

    for (int i=0; i<n; i++) {
        
        if (s[i] == '[' || s[i] == '{' || s[i] == '(') st.push(s[i]);

        else {    
            if (st.size() == 0) return false; //Case where opening brackets are less than closing

            if ((st.top() == '(' && s[i] == ')') || 
            (st.top() == '[' && s[i] == ']') || 
            (st.top() == '{' && s[i] == '}')) {
                st.pop();
            } else return false; // If no match then false
        }
    }

    return st.size()==0; //If stack is empty, returns true or else false
    
}


int main() {
    //"{([])}"
    return 0;
}