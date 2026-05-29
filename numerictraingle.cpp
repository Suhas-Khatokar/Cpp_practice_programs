#include<iostream>

using namespace std;

int main() {
    int n;
    cout<<"Enter no of rows: ";
    cin>>n;

    for(int i=1; i<=n; i++) {

    // spaces
        for(int j=1; j<=n-i; j++) {
            cout << " ";
        }

    // numbers
        for (int k=1; k<=(2*i-1); k++) {
            if (k>=1 && k <=i) {
                cout << k;
            }
        }

        for (int l=i-1; l>=1; l--) {
            cout << l;
        }

    cout << endl;
}



    return 0;
}