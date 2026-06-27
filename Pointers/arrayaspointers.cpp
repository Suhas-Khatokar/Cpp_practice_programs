#include<iostream>
using namespace std;

void arrayPointer (int *arr, int n) {
    for (int i=0; i<n; i++) {
        cout<<*(arr+i)<<" "; //short form is cout<<arr[i]<<" "
    }

    //Since arr points to the address of first element of actual array, changes here will be afected
    //in actual array
    *(arr+1) = 67;

}

int main() {
    //Array's name is a pointer which stores the address of first element of array {0th index}
    int arr[4] = {1, 2, 3, 4};
    cout<<arr<<endl; //Prints the address of arr[0]
    cout<<*arr<<endl; //Prints arr[0]

    //You can using operators on pointers
    //arr+1 means stores the address of next storage bucket, which here points to the next element's address
    cout<<*(arr+1)<<endl;

    arrayPointer(arr, 4);
    //Now if elements printed again, arr[1] changes to 67


    return 0;
}