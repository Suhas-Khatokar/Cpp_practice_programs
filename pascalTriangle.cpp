#include<iostream>
using namespace std;
#include<vector>

int main() {
    //Imp 2D Vector theory
    /*
    1D vector: vector <datatype> vector_name;
    2D vector: vector <vector <int>> vector_name;

    Defining a vector of n rows and m columns

    vector <vector <int>> V(n, vector<int>(m, value assigned at each element {0 by default}));

    3*3 vector

    V = {{1, 2, 3}, 
        {4, 5}, 
        {6, 7, 8}}

    Can have some spaces empty as its dynamic
    */

    
    int n;
    cout<<"Enter the no of rows: ";
    cin>>n;
    vector<vector<int>> V(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j==0 || j==i) {
                V[i][j] = 1;
            }
            else {
                V[i][j] = V[i-1][j] + V[i-1][j-1];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << V[i][j] << " ";
        }
        cout << endl;
    }

    /*
    This is not very efficient as an nxn matrix is created
    [0 0 0 0 0]
    [0 0 0 0 0]
    [0 0 0 0 0]
    [0 0 0 0 0]
    [0 0 0 0 0] (n=5)
    */

    //Better method

    vector<vector<int>> V(n);

    //V has n rows, but each row is initially empty.



    for (int i = 0; i < V.size(); i++) {
        V[i].resize(i + 1);
        /*
        [0]
        [0 0]
        [0 0 0]
        [0 0 0 0]
        [0 0 0 0 0] 
        */

        for (int j = 0; j < V[i].size(); j++) {
            if (j == 0 || j == i) {
                V[i][j] = 1;
            } else {
                V[i][j] = V[i - 1][j - 1] + V[i - 1][j];
            }
        }
    }


    for (int i = 0; i < V.size(); i++) {
        for (int j = 0; j < V[i].size(); j++) {
            cout << V[i][j] << " ";
        }
        cout << endl;
    }


    

    return 0;
}