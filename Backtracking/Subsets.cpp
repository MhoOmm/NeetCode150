class Solution {
public:
    void solve(int i,vector<int>&nums,vector<vector<int>>&result,vector<int>&curr)
    {
        if(i>=nums.size())
        {
            result.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        solve(i+1,nums,result,curr);
        curr.pop_back();
        solve(i+1,nums,result,curr);

    }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>>result;
        vector<int>curr;
        solve(0,nums,result,curr);
        return result;
    }
};
