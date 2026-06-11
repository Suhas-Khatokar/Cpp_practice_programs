#include<iostream>
using namespace std;


void sortZeroesAndOnes(int array[], int size) {
    //Approach 1: Traverse once (two pointers)
    int lp = 0;
    int rp = size-1;

    while (lp < rp) {
        if (array[lp] == 1 && array[rp] == 0) {
            array[lp] = 0;
            array[rp] = 1;
            lp++;
            rp--;
        }
        if (array[lp] == 0) {
            lp++;
        }

        if (array[rp] == 1) {
            rp--;
        }

    }
    //Approach 2: Traverse twice
    int c0 = 0;
    for (int i=0; i<size; i++) {
        if (array[i] == 0) {
            c0++;
        }
    }

    for (int j=0; j<size; j++) {
        if (j<c0) {
            array[j] = 0;
        }

        else {
            array[j] = 1;
        }
    }
}

//& important for updation of values
void swapval (int &a, int &b) {
    int c = 0;
    c = a;
    a = b;
    b = c;
}

void sortOddEvens (int array[], int n) {
    int lp = 0;
    int rp = n-1;

    while (lp < rp) {
        if (array[lp] % 2 != 0 && array[rp] % 2 == 0) {
            swapval(array[lp], array[rp]);
            lp++;
            rp--;
        }

        if (array[lp] % 2 == 0) {
            lp++;
        }

        if (array[rp] % 2 != 0) {
            rp--;
        }

    }
}


int main() {
    //Sort only 0s and 1s (Output => {0, 0, 1, 1, 1})
    int array[] = {1, 1, 0, 0, 1, 0, 1, 0};
    int size = sizeof(array)/sizeof(array[0]);
    for (int &x:array) {
        cout<<x<<" ";
    }
    cout<<endl;

    sortZeroesAndOnes(array, size);

    for (int &x:array) {
        cout<<x<<" ";
    }

    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a)/sizeof(a[0]);
    for (int &x:a) {
        cout<<x<<" ";
    }
    cout<<endl;

    sortOddEvens(a, n);

    for (int &x:a) {
        cout<<x<<" ";
    }

    int arr[] = {-4, -2, 1, 3, 5};
    int s = sizeof(arr)/sizeof(arr[0]);
    for (int &x:arr) {
        cout<<x<<" ";
    }
    cout<<endl;

    squaredArray(arr, s);

    for (int &x:arr) {
        cout<<x<<" ";
    }

    return 0;
}