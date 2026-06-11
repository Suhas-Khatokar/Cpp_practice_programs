#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void squareSortedArray(vector <int> &v) {
    int lp = 0;
    int rp = v.size()-1;

    vector <int> ans;

    while (lp<=rp) {
        if (abs(v[rp])>abs(v[lp])) {
            ans.push_back(v[rp]*v[rp]);
            rp--;
        }
        else {
            ans.push_back(v[lp]*v[lp]);
            lp++;
        }
    }
    
    reverse(ans.begin(), ans.end());
    for (int &x:ans) {
        cout<<x<<" ";
    }
}

int main() {
    int n;
    vector <int> v;
    cout<<"Enter the no of elements: ";
    cin>>n;

    for (int i = 0; i<n; i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }

    for (int &x:v) {
        cout<<x<<" ";
    }
    cout<<endl;

    squareSortedArray(v);


    return 0;
}