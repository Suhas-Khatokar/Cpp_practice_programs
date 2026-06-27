#include<iostream>
using namespace std;

int main() {

    int x, y; //x means column and y means row
    cin>>x;
    cin>>y;

    for (int i=1; i<=y; i++) {
        for (int j=1; j<=x; j++) {
                cout <<"*";
            }
        cout<<endl; 
    }



    return 0;
}