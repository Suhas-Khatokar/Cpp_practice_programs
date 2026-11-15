#include <iostream>
#include <vector>
using namespace std;
//Find the min cost to reach the final stair
//Each index gives the cost to go to next stair, only 2 choices - i+1, i+2
//cost = |v[i] - v[i+1]| or |v[i] - v[i+2]| 

//Using recursion and memoisation 
int frog_jump(vector <int> &v, int i, vector <int> &dp) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    int x = frog_jump(v, i-1, dp) + abs(v[i] - v[i-1]);
    int y = INT_MAX;
    if (i>1) y = frog_jump(v, i-2, dp) + abs(v[i] - v[i-2]);
    return dp[i] = min(x, y);
}

//Using tabulation

int frog_jump_tabulation(vector <int> &v, vector <int> &dp) {
    int n = v.size();
    if (n==1) return 0;
    dp[1] = abs(dp[1]-dp[0]);
    for (int i=2; i<n; i++) {
        int jump1 = dp[i-1]+abs(v[i-1]-v[i]);
        int jump2 = dp[i-2]+abs(v[i-2]-v[i]);
        dp[i] = min(jump1, jump2);
    }
    return dp[n-1];
}

int main() {
    vector <int> v = {30, 20, 50, 10, 40};
    int n = v.size();
    vector <int> dp(n+1, -1);
    int min_cost = frog_jump(v, n-1, dp);
    int minc = frog_jump_tabulation(v, dp);
    cout<<min_cost;
    //cout<<minc;
    return 0;
}