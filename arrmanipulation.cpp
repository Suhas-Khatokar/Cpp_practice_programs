#include<iostream>
#include<vector>
using namespace std;
#include <algorithm> //For reverse function

int main() {
    //Unique numbers if elements repeated twice

    int array[] = {2, 2, 3, 3, 7, 5, 6, 5, 6};
    int size = sizeof(array)/sizeof(array[0]);
    int unique = 0;

    //Brute force
    for (int i=0; i<size; i++) {
        int pairs = 0;

        for (int j=0; j<size; j++) {
            if (i != j && array[i] == array[j]) {
                pairs = 1;
                break;
            }
        }

        if (pairs == 0) {
            unique = array[i];
        }
    }
    cout<<"Unique element is: "<<unique;

    //Manipulation method
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] == array[j]) {
                array[i] = array[j] = -1;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            cout << array[i] << endl;
        }
    }

    //Second largest Array

    int array1[] = {2, 3, 4, 7, 6, 5, 7, 7, 8};
    int size1 = sizeof(array1)/sizeof(array1[0]);

    int max = array1[0];
    for (int i = 1; i < size1; i++) {
        if (array1[i] > max)
            max = array1[i];
    }

    int max2 = -1;   // assuming all elements are non-negative

    for (int i = 0; i < size1; i++) {
        if (array1[i] != max && array1[i] > max2)
            max2 = array1[i];
    }

    if (max2 == -1)
        cout << "No second largest element";
    else
        cout << max2;

    //Rotate given array a by k steps
    //Eg: [1, 2, 3, 4, 5] k=2 ---> [4, 5, 1, 2, 3]


    //Approach 1: using arrays
    int a[] = {1, 2, 3, 4, 5}; //Output --> {6, 7, 1, 2, 3, 4, 5}
    int s = sizeof(a)/sizeof(a[0]);

    for (int &element:a) {
        cout<<element<<" ";
    }
    cout<<endl;

    int k = 2;
    k = k%s; //(To taken in account of k more than size)
    int n = s-k;

    int newarray[s];

    for (int j=0; j<s; j++) {
        newarray[j] = a[s-k+j];
    }

    for (int i=0; i<n; i++) {
        newarray[i+k] = a[i];
    }

    for (int &element:newarray) {
        cout<<element<<" ";
    }
    cout<<endl;

    //Approach 2: using vectors(done in the same array)
    cout<<"Enter size of array: ";
    cin>>n;
    vector <int> v;

    for (int i = 0; i<n; i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }

    // IMP NOTE:
    // reverse(first, last) works on [first, last)
    // Lower bound INCLUDED, upper bound EXCLUDED

    // Here reverse(0, 5) conceptually means [0, 5)

    reverse(v.begin(), v.end());      // {5, 4, 3, 2, 1}

    reverse(v.begin(), v.begin()+k);  // {4, 5, 3, 2, 1}
    // If k = 2, reverse indices 0 and 1

    reverse(v.begin()+k, v.end());    // {4, 5, 1, 2, 3}
    // If k = 2, reverse indices 2, 3, 4

    for (int &element:v) {
        cout<<element<<" ";
    }

    return 0;
}