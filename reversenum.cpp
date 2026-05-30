#include<iostream>

using namespace std;

int main () {   
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int revnum = 0;

    while (n>0) {
        int rem = n%10;
        revnum = revnum*10 + rem;
        n=n/10;
    }

    cout<<"Reversed number: "<<revnum;

    return 0;
}