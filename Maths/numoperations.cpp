#include<iostream>

using namespace std;

int main () {
    //No of digits and Sum of digits
    int n;
    int sum = 0;
    int digits = 0;

    cout << "Enter a number: ";
    cin >> n;

    while (n>0) {
        digits = digits + 1;
        sum = sum + (n%10);
        n = n/10;
    }

    cout<<"No of digits = "<<digits<<endl;
    cout<<"Sum of digits = "<<sum;

    return 0;
}