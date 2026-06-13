#include<iostream>
using namespace std;

void runningSum(int array[], int n) {
    int new_ele = 0;
    for (int i=0; i<n; i++) {
        new_ele += array[i];
        array[i] = new_ele;

        //Better approach:
        //array[i] += array[i-1] (i goes from 1 to n-1)
    }

    for (int i=0; i<n; i++) {
        cout<<array[i]<<" ";
    }
}

void prefixSuffixSum(int array[], int n) {
    int prefixSum = 0;
    int suffixSum = 0;
    int sum = 0;

    bool partition = false;

    for (int s=0; s<n; s++) {
        sum += array[s];
    }

    for (int i=0; i<n; i++) {
            prefixSum += array[i];
            suffixSum = sum - prefixSum;

        if (prefixSum == suffixSum) {
            partition = true;
            break;
        }
    }

    cout<<partition;
}

void sumUsingIndices(int array[], int l, int r) {

    int q;
    cout<<"Enter the no of queries: ";
    cin>>q;

    while (q--) {
        int req_sum = 0;
        int prefix_ele = 0;

        for (int i=l-1; i<r; i++) {
            req_sum += array[i];
        }

        cout<<req_sum;
    }

}


int main() {
    int n;
    cout<<"Enter the no of elements in array: ";
    cin>>n;
    int array[n];

    for (int i=0; i<n; i++) {
        int x;
        cin>>x;
        array[i] = x;
    }

    for (int i=0; i<n; i++) {
        cout<<array[i]<<" ";
    }
    cout<<endl;

    int l; int r;
    cout<<"Enter left index: ";
    cin>>l;
    cout<<"Enter right index: ";
    cin>>r;

    //runningSum(array, n);
    //prefixSuffixSum(array, n);
    sumUsingIndices(array, l, r); //1 based indexing

    return 0;
}