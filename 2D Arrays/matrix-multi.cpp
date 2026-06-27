#include<iostream>
using namespace std;

int main () {
    int m;
    int n;

    cout<<"Enter no of rows: ";
    cin>>n;
    cout<<"Enter no of columns: ";
    cin>>m;

    int matrix_1[n][m];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout<<"Enter the element: ";
            cin>>matrix_1[i][j];
        }
    }

    int x;
    int y;

    cout<<"Enter no of rows: ";
    cin>>x;
    cout<<"Enter no of columns: ";
    cin>>y;

    int matrix_2[x][y];

    if (m==x) {
        for (int i=0; i<x; i++) {
            for (int j=0; j<y; j++) {
                cout<<"Enter the element: ";
                cin>>matrix_2[i][j];
            }
        }

        int multiplied_matrix[n][y];

        for (int i=0; i<n; i++) {
            for (int k=0; k<y; k++) {
                int ele = 0;
                for (int j=0; j<m; j++) {
                    ele += matrix_1[i][j]*matrix_2[j][k];
                    
                }
                multiplied_matrix[i][k] = ele;       
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<y; j++) {
                cout<<multiplied_matrix[i][j]<<" ";
            }
            cout<<endl;
        }

    }

    else {
        cout<<"Invalid matrix multiplication"<<endl;
    }

    
    return 0;
}