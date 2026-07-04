#include<iostream>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cout<<"Enter a string (a-z): ";
    cin>>str;

    int n = str.length();
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (str[j]>str[j+1]) {
                swap(str[j], str[j+1]);
            }
                
        }
    }
    cout<<str;

    return 0;
}