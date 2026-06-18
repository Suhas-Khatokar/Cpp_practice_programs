#include <iostream>
#include <vector>
using namespace std;

void swapval (int &a, int &b) {
    int c = 0;
    c = a;
    a = b;
    b = c;
}

void maxOnesRow(vector<vector<int>> &matrix) {
    int row = -1;
    int max_1 = -1;
    int c = matrix[0].size();

    for (int i = 0; i < matrix.size(); i++) {
        int noOfOnes = 0;

        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 1) {
                noOfOnes = c - j;
                break;
            }
        }

        if (noOfOnes > max_1) {
            max_1 = noOfOnes;
            row = i;
        }
    }

    cout << row;
}

void matrixRotation(vector <vector<int>> &matrix) {
    //Rotation of matrix by 90 deg clockwise

    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[i].size(); j++) {
            if (i>j) {
                swapval(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    for (int i=0; i<matrix.size(); i++) {
        int rctr = matrix[0].size()-1;
        int lctr = 0;
        while (rctr>lctr) {
            swapval(matrix[i][rctr], matrix[i][lctr]);
            lctr++;
            rctr--;
        }
        //or use reverse(matrix[i].begin(), matrix[i].end()); for above
    }

    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[i].size(); j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int n, m;

    cout << "Enter the no of rows: ";
    cin >> n;

    cout << "Enter the no of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Enter a number: ";
            cin >> matrix[i][j];
        }
    }

    //maxOnesRow(matrix);
    matrixRotation(matrix);

    return 0;
}