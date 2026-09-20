#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> ans;
vector <int> v;

vector<vector<int>> subsets(vector<int>& nums, int i) {
    if (i==nums.size()) {
        return ans;
    }
    v.push_back(nums[i]);
    ans.push_back(v);
    subsets(nums, i+1);
    v.pop_back();
    subsets(nums, i+1);

    return ans;
}
int main() {
    vector <int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums, 0);
    for (int i=0; i<ans.size(); i++) {
        for (int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}