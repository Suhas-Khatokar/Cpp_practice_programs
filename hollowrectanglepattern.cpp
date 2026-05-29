#include<iostream>
using namespace std;
int main(){
    int x, y; //x means column and y means row
    cin>>x;
    cin>>y;

    for (int i=1; i<=y; i++) {

        if (i==1 || i == y) {
            for (int j=1; j<=x; j++) {
                cout <<"*";
            }
            cout<<endl;    
        }

        else {
            for (int l=1; l<=x; l++) {
                if (l==1 || l==x) {
                    cout << "*";
                }

                else {
                    cout << " ";
                }
            }
            cout<<endl;  
        }
        
    }


    return 0;

}