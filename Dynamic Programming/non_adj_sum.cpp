#include <iostream>
#include <vector>
using namespace std;
//House robber question from leetcode
//TC-O(n), SC-O(n) {Recursion Stack space} + O(n) {Array space}
int maxSumMemoization(vector <int> &nums, int i, vector <int> &dp) {
    if (i < 0) return 0;
    if (i == 0) return nums[0];
    if (dp[i] != -1) return dp[i];
    int pick = nums[i] + maxSumMemoization(nums, i-2, dp);
    int not_pick = 0 + maxSumMemoization(nums, i-1, dp);
    return dp[i] = max(pick, not_pick);
}

//TC-O(n), SC-O(n) {Array space}
int maxSumTabulation(vector <int> &nums, vector <int> &dp) {
    dp[0] = nums[0];
    for (int i=1; i<nums.size(); i++) {
        int pick = nums[i];
        if (i>1) pick+= dp[i-2]; //(To take in account the case where i becomes -ve)
        int not_pick = 0 + dp[i-1];
        dp[i] = max(pick, not_pick);
    }
    return dp[nums.size()-1];
}
//TC-O(n), SC-O(1) 
int maxSumBest(vector <int> &nums) {
    int prev1 = nums[0];
    int prev2 = 0;
    for (int i=1; i<nums.size(); i++) {
        int pick = nums[i];
        if (i>1) pick+=prev2; //(To take in account the case where i becomes -ve)
        int not_pick = 0 + prev1;
        int curr = max(pick, not_pick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    vector <int> nums = {1, 2, 3, 4, 5, 6};
    vector <int> dp(nums.size()+1, -1);
    cout<<maxSumMemoization(nums, nums.size()-1, dp)<<endl;
    cout<<maxSumTabulation(nums,  dp)<<endl;
    cout<<maxSumBest(nums);
    return 0;
}