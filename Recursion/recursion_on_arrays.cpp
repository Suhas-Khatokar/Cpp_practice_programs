#include<iostream>
#include<vector>
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

void findElement(int *arr, int n, int i, int x) {
    if (i==n){
        cout<<"No";
        return; 
    } 
    if (x==arr[i]){
        cout<<"Yes";
        return;
    }

    findElement(arr, n, i+1, x);
}

void subsetSum(int *arr, int n, int i, vector <int> &result, int sum) {
    if (i==n) {
        result.push_back(sum);
        return;
    }

    subsetSum(arr, n, i+1, result, sum + arr[i]); //pick the ith element
    subsetSum(arr, n, i+1, result, sum); //do not pick the ith element
}

void reverseArray(int *arr, int i, int size) {
    if (i==size/2) return;
    swap(arr[i], arr[size-i]);
    reverseArray(arr, i+1, size);
}

int main() {

    /*int arr[6] = {2, 3, 5, 20, 1, 0};
    printArray(arr, 6, 0);

    int max_ele = maxElement(arr, 6, 0);
    cout<<max_ele;
    
    int sum = sumOfElements(arr, 6, 5);
    cout<<sum;

    findElement(arr, 6, 1, 45);

    int arr[] = {1, 2, 3};
    vector<int> result;
    subsetSum(arr, 3, 0, result, 0);

    for (int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }*/

    int arr[] = {1, 2, 3, 4, 5};
    reverseArray(arr, 0, 4);

    for (int i=0; i<5; i++) {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}