#include <iostream>
#include <vector>
using namespace std;
//House robber question from leetcode
//TC-O(n), SC-O(n) {Recursion Stack space} + O(n) {Array space}
int maxSum(vector <int> &nums, int i, vector <int> &dp) {
    if (i < 0) return 0;
    if (i == 0) return nums[0];
    if (dp[i] != -1) return dp[i];
    int pick = nums[i] + maxSum(nums, i-2, dp);
    int not_pick = 0 + maxSum(nums, i-1, dp);
    return dp[i] = max(pick, not_pick);
}

int main() {
    vector <int> nums = {1, 2, 3, 4, 5, 6};
    vector <int> dp(nums.size()+1, -1);
    cout<<maxSum(nums, nums.size()-1, dp);
    return 0;
}