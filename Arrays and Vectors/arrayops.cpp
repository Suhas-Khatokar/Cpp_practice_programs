#include<iostream>

using namespace std;

int main() {
    int n;
    cout<<"Enter the no of elements: ";
    cin>>n;

    int array[n];
    for (int i=0; i<n; i++) {
        cout <<"Enter the element: ";
        cin>>array[i];
    }
//Sum of elements
    int sum=0;
    for (int &element:array) {
        sum += element;
    }
    cout<<"Sum of elements is: "<<sum<<endl;


//Max of element
    int max=array[0]; //(To also take in account for -ve num)
    for (int i=0; i<n; i++) {
        if (array[i]>max) {
            max = array[i];
        }    
    }
    cout<<"Maximum element: "<<max;

    //Linear search

    int array2[] = {1, 2, 3, 4, 5};

    int size = sizeof(array2)/sizeof(array2[0]);

    int x;
    cout<<"Enter the element to search: ";
    cin>>x;
    int index = -1;

    for (int i=0; i<size; i++) {
        if (x == array2[i]) {
            index = i;
            break; 
        }
    }
    cout<<index;
}