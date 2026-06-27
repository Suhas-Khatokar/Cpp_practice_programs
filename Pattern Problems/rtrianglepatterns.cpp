#include<iostream>

using namespace std;

int main() {
    int y;
    cout << "Enter no of rows: ";
    cin >> y;
    for (int i=1; i<=y; i++) {
        for (int k=1; k<=i; k++) {
            cout<<"*";
        }
        cout<<endl;
    }

    /*eg output:
    *
    **
    ***
    (for y=3)
    */

    int n;
    cout << "Enter no of rows: ";
    cin >> n;

    for (int j=n; j>=1; j--) {
        for (int l=j; l>=1; l--) {
            cout<<"*";

        }
        cout<<endl;
       
    }

     /*eg output:
    ***
    **
    * 
    (for y=3)
    */

    return 0;
}

