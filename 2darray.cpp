#include<iostream>
using namespace std;

int main() {
    /*Theory for n dimensional arrays:
    datatype array_name[size1][size2]......[sizeN];
    
    2D array: datatype array_name[row][column];*/

    //Taking input in 2D array

    int m;
    int n;

    cout<<"Enter no of rows: ";
    cin>>n;
    cout<<"Enter no of columns: ";
    cin>>m;

    int array[n][m];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout<<"Enter the element: ";
            cin>>array[i][j];
        }
    }

    //Output array
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}