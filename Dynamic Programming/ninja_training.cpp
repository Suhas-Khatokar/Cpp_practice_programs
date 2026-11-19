#include <iostream>
#include <vector>
using namespace std;
//My solution
int maxPoints(vector <vector<int>> &v, int i, int j, vector <vector<int>> &dp) {
    if (i<0 || j<0 || j>2) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int a = v[i][j] + maxPoints(v, i-1, j-1, dp);
    int b = v[i][j] + maxPoints(v, i-1, j-2, dp);
    int c = v[i][j] + maxPoints(v, i-1, j+1, dp);
    int d = v[i][j] + maxPoints(v, i-1, j+2, dp);

    int max1 = max(a, b);
    int max2 = max(c, d);
    return dp[i][j] = max(max1, max2);
}

//Striver solution
int solve(vector<vector<int>>& v, int i, int last, vector<vector<int>>& dp) {
    if (i<0) return 0;
    if (dp[i][last] != -1) return dp[i][last];
    int maxi = 0;
    for (int j = 0; j < 3; j++) {
        if (j != last) {
            int points = v[i][j] + solve(v, i-1, j, dp);
            maxi = max(maxi, points);
        }
    }

    return dp[i][last] = maxi;
}

int main() {
    vector <vector <int>> training = {
        
    {50, 10, 10},
    {100, 1, 1},
    {50, 10, 10}

    };
    int m = training.size();
    vector <vector <int>> dp(m, vector <int> (3, -1));
    int ans = max(max(maxPoints(training, 2, 2, dp), maxPoints(training, 2, 1, dp)), maxPoints(training, 2, 0, dp));
    cout<<ans<<endl;
    cout<<solve(training, 2, 2, dp);
    return 0;
}