#include<iostream>
using namespace std;

int factorial (int n) {
    if (n==1 || n==0) return 1;
    return n*factorial(n-1);
}

int fibonacci (int x) {
    if (x==0) return 0;
    if (x==1) return 1;

    return fibonacci(x-1) + fibonacci(x-2);
}

int sumOfDigits (int num) {
    // x=x/10, sum += x%10
    if (num<10 && num>0) return num;
    return num%10 + sumOfDigits(num/10);
}

int power(int x, int y) {
    //x^y i.e., x*x*x.... (y times)
    if (y==0) return 1;
    return x*power(x, y-1);
}

void increasingSequence(int i, int n) {
    if (i==n+1) return;
    cout<<i<<" ";
    increasingSequence(i+1, n);
}

void kmultiples (int n, int k) {
    if (k==0) return;
    kmultiples(n, k-1);
    cout<<n*k<<" ";
}

int altSeq(int n) {
    //n=4 => 1-2+3-4 = -2
    if (n==1) return 1;
    if (n%2==0) return altSeq(n-1)-n; 
    return altSeq(n-1)+n;

}

int GCD(int x, int y) {
    if (y>x) return GCD(y, x);
    if (y==0) return x;
    return GCD(y, x%y); //using euclid's algo
}

int armstrong_sum(int x) {
    if (x>0 && x<10) return power(x, 3);
    return armstrong_sum(x/10) + power(x%10, 3);
}


int main() {
    //increasingSequence(1, 10);
    //kmultiples(7, 5);
    //int sum = altSeq(10);
    //int hcf = GCD(4, 5);
    //int arm = armstrong(153);
    return 0;
}