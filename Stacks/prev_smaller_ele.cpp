#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Prev smaller ele: The element which is immediately smaller than the current element and is to the 
//left side of array (-1 if doesnt exist)

//Eg {3, 1, 0, 8, 6}
//ans {-1, -1, -1, 0, 0}
vector <int> PrevSmallerEle(vector <int> nums) {
    vector<int> ans;
    stack <int> st;
    for (int i=0; i<nums.size(); i++) {
        while (st.size()>0 && st.top()>=nums[i]) st.pop();

        if (st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(nums[i]);
    }
    return ans;

}

int main() {
    vector <int> nums = {3, 1, 0, 8, 6};
    vector <int> ans = PrevSmallerEle(nums);

    for (int &x:ans) {
        cout<<x<<" ";
    }
    return 0;
}