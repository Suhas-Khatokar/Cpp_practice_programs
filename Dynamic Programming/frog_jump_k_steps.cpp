#include <iostream>
#include <vector>
using namespace std;
//Find the min cost to reach the final stair
//Each index gives the cost to go to next stair, only k choices - i+1, i+2,.....i+k
//cost = |v[i] - v[i+1]| or |v[i] - v[i+2]| .... |v[i] - v[i+k]|

int frog_jump(vector <int> &v, int i, vector <int> &dp, int k) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    int min_steps = INT_MAX;
    for (int j=1; j<=k; j++) {
        if (i > j) {
            int jump = frog_jump(v, i-j, dp, k) + abs(v[i]-v[i-j]);
            if (jump>min_steps) min_steps = jump;
        }
    }
    return dp[i] = min_steps;
}


int main() {

    return 0;
}