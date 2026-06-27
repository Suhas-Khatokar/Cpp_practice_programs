#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector <int> &v) {
    int n = v.size();
    bool flag = false;
    //i has one less iteration since the last element will be in the correct place itself
    //j max val is n-i-2 to take in account the j+1 ele and the last i elements are already sorted
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (v[j]>v[j+1]){
                flag = true;
                swap(v[j], v[j+1]);
            } 
        }
        if (!flag) break; //Better optimisation for nearly sorted array
    }

}

int main() {
    int n;
    cout<<"Enter the no of elements: ";
    cin>>n;
    vector<int> v(n);

    for (int i=0; i<n; i++) {
        cin>>v[i];
    }

    bubbleSort(v);

    for (int i=0; i<n; i++) {
        cout<<v[i]<<" ";
    }


    return 0;
}

