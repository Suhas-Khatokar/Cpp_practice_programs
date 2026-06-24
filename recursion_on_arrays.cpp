#include<iostream>
using namespace std;

void printArray(int *arr, int n, int i) {
    if (i==n) return;
    cout<<arr[i]<<" ";
    printArray(arr, n, i+1);
}

int maxElement(int *arr, int n, int i) {
    if (i==n-1) return arr[i];
    return max(arr[i], maxElement(arr, n, i+1)); //max is an inbuilt function
}

int sumOfElements (int *arr, int n, int i) {
    if (i==0) return arr[i];    
    return arr[i] + sumOfElements(arr, n, i-1);
}

int main() {

    int arr[6] = {2, 3, 5, 20, 1, 0};
    printArray(arr, 6, 0);

    int max_ele = maxElement(arr, 6, 0);
    cout<<max_ele;
    
    int sum = sumOfElements(arr, 6, 5);
    cout<<sum;
    
    return 0;
}