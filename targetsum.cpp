#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the no of elements: ";
    cin>>n;
    int array[n];

    for (int i=0; i<n; i++) {
        cout<<"Enter the element: ";
        cin>>array[i];
    }

    int sum;
    cout<<"Enter required sum: ";
    cin>>sum;

    //Target sum with pairs
    int pairs = 0;

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (array[i]+array[j] == sum) {
                pairs++;
            }
        }       
    }
    
    cout<<pairs;

    //Target sum with triplets
    int triplets = 0;

    for (int i=0; i<n-2; i++) {
        for (int j=i+1; j<n-1; j++) {
            for (int k=j+1; k<n; k++) {
                if (array[i]+array[j]+array[k] == sum) {
                triplets++;
            } 
            }
        }       
    }
    cout<<triplets;



    return 0;
}