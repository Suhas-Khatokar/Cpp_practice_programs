#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*The span of the stock's price in one day is the maximum number of consecutive days 
(starting from that day and going backward) for which the stock price was less than 
or equal to the price of that day.*/

//[100, 80, 60, 70, 60, 75, 85]
//[1, 1, 1, 2, 1, 4, 6]

vector<int> StockSpan(vector <int> stocks) {
    vector <int> ans;

    //Brute force soln
    for (int i=0; i<stocks.size(); i++) {
        int count = 0;

        for (int j=i; j>=0; j--) {
            if (stocks[i] >= stocks[j]) count++;
            else break;
        }

        ans.push_back(count);
    }

    
    return ans;
}


int main() {
    vector <int> stocks;
    cout<<"Enter the no of stocks";
    int n;
    cin>>n;

    for (int i=0; i<n; i++) {
        int x;
        cin>>x;
        stocks.push_back(x);
    }

    vector <int> ans = StockSpan(stocks);
    for (int i=0; i<n; i++) {
        cout<<ans[i]<<" ";
    }

    return 0;
}