#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cout<<"Enter the no of elements: ";
    cin>>n;
    vector<int> v;
    int element; 

    for (int i=0; i<n; i++) {
        cin>>element;
        v.push_back(element);
    }

    //Last occurence of x
    int x;
    cout<<"Enter a number: ";
    cin>>x;
    int index = -1;
    int c = 0;

    for (int i=0; i<v.size(); i++) {
        if (x == v[i]) {
            index = i;
        }
    }
    cout<<"Index of last occurence is: "<<index<<endl;

    //(A more efficient way):
    for (int i=v.size()-1; i>=0; i--) {
        if (x == v[i]) {
            index = i;
            break;
        }
    }

    cout<<"Index of last occurence is: "<<index;

    //No of occurence
    for (int i=0; i<v.size(); i++) {
        if (x == v[i]) {
            c+=1;
        }
    }

    cout<<"No of occurence is: "<<c;

    //Sorted checking
    int sorted = 0;
    for (int i=0; i<v.size()-1; i++) {
        if (v[i+1] >= v[i]) {
            sorted = 1;
        }
        else {
            sorted = 0;
            break;
        }
    }
    cout<<sorted;


    return 0;
}