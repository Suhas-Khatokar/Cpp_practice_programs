#include<iostream>
using namespace std;

int main() {
    //Addition using pointers
    int x,y;
    cin>>x>>y;

    int *ptr_x = &x; //Stores the address of x
    int *ptr_y = &y; //Stores the address of y

    int sum;

    int *ptr_sum = &sum;

    *ptr_sum = *ptr_x + *ptr_y; //Dereferencing, ie you can access x using *ptr_x

    cout<<*ptr_sum<<endl;
    cout<<sum<<endl; //sum is also updated and becomes x+y since *ptr_sum is literally pointing at sum

    cout<<ptr_sum<<endl; //Prints the address of sum variable
    cout<<&ptr_sum; //Prints the address of ptr_sum pointer
    return 0;
}