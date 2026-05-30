#include<iostream>

using namespace std;

int main () {
    //To find the sum of S = 1-2+3-4..............n

    int n;
    cout << "Enter a number: ";
    cin >> n;

    int sum = 0;

    for (int i=1; i<=n; i++) {
        if (i%2==0) {
            sum = sum-i;
        }

        else {
            sum = sum+i;
        }
    }

    cout<<"Sum of the series: "<<sum;


    return 0;
}