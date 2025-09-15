class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n  = nums.size();
        unordered_map<int,int>mp;
        vector<int>result(2);
        for(int i=0;i<n;i++)
        {
            int bud = target - nums[i];
            if(mp.find(bud) != mp.end())
            {
                return {mp[bud],i};
            }
            mp[nums[i]] = i;
        }

        return {};
    }
};
