#include<iostream>
using namespace std;

int main() {
    int m;
    int n;

    cout<<"Enter no fo rows: ";
    cin>>m;
    cout<<"Enter no fo columns: ";
    cin>>n;

    int matrix[m][n];

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cout<<"Enter the element: ";
            cin>>matrix[i][j];
        }
    }

    int matrix_transpose[n][m];

    cout<<"Original matrix: "<<endl;

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Matrix transpose: "<<endl;


    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            matrix_transpose[i][j] = matrix[j][i];
            cout<<matrix_transpose[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}