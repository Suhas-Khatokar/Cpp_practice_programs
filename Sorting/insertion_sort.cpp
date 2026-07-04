#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int> &v) {
    int n = v.size();

    for (int i=1; i<n; i++) {
        int current = v[i];
        int j = i-1;
        //Finding the correct j or pos where element should be inserted
        while (j>=0 && v[j]>current) {
            v[j+1] = v[j];
            j--;
        }
        //Inserting current element
        v[j+1] = current;
    }

    
}
//Left side-sorted, right side-unsorted
//{5,| 3, 4, 1, 2}
//{3, 5,| 4, 1, 2} 
//{3, 4, 5,| 1, 2} 
//{1, 3, 4, 5,| 2}
//{1, 2, 3, 4, 5} 


int main() {
    int n;
    cout<<"Enter the no of elements: ";
    cin>>n;
    vector<int> v(n);

    for (int i=0; i<n; i++) {
        cin>>v[i];
    }

    insertionSort(v);

    for (int i=0; i<n; i++) {
        cout<<v[i]<<" ";
    }

    return 0;
}