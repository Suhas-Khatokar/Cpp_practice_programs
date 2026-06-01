#include<iostream>

using namespace std;

int main () {
    // Binary to decimal
    /*int n;
    cin >> n;

    int num = 0;
    int p2 = 1;

    while (n>0) {
       
        num = num + (p2*(n%10));
        n=n/10;
        p2 = p2*2;
    }

    cout<<num;*/

    //Decimal to binary
    int m;
    cin >> m;

    int bnum = 0;

    while (m>0) {
        bnum = bnum*10 + (m%2);
        m=m/2;
    }
    
    return 0;
}