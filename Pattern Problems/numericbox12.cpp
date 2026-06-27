#include<iostream>

using namespace std;

int main() {
    int n;
    int m;

    cout << "Enter no of rows: ";
    cin>>n;

    cout << "Enter no of columns: ";
    cin >> m;

    for (int i=1; i<=n; i++) {
        if (i%2!=0) {
            for (int j=1; j<=m; j++) {
                if (j%2!=0) {
                    cout << "1";
                }
                else{
                    cout << "2";
                }
            }
            cout<<endl;

        }
        


        else {
            for (int j=1; j<=m; j++) {
                if (j%2!=0) {
                    cout << "2";
                }
                else{
                    cout << "1";
                }
            }
        cout<<endl;
        }

    }

    /*output eg
    12121     where n=4, m=5
    21212
    12121
    21212
    */


    //OR USE THIS

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if ((i + j) % 2 == 0) {
                cout << "1";
            }

            else {
                cout << "2";
            }
        }

        cout << endl;
}

    return 0;
}