#include <iostream>
#include <vector>
using namespace std;

vector <vector<int>> ans;
vector <int> v;

void getPermutations(vector<int>& nums) {
    if (v.size() == nums.size()) {
        ans.push_back(v);
        return;
    }

    for (int  i=0; i<nums.size(); i++) {
        bool used = false;

        for (int j = 0; j < v.size(); j++) {
            if (v[j] == nums[i]) {
                used = true;
                break;
            }
        }

        if (used) continue;

        v.push_back(nums[i]);
        getPermutations(nums);
        v.pop_back();
    }
}

int main() {
    vector <int> nums = {1, 2, 3, 4};
    getPermutations(nums);
    for (int i=0; i<ans.size(); i++) {
        for (int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}