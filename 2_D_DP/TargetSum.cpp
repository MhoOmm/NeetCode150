// top down approach
class Solution {
public:
    int t[1001][2001];
    int solve(vector<int>&nums,int i,int sum,int target,unordered_map<string,int>&mp)
    {
        if(i==nums.size())
        {
            if(sum==target)
            {
               return 1;
            }else{return 0;}
        }
        string key = to_string(i)+"_"+to_string(sum);

        if(mp.count(key))
        {
            return mp[key];
        }

        int plus = solve(nums,i+1,sum+nums[i],target,mp);
        int minus = solve(nums,i+1,sum-nums[i],target,mp);

        return mp[key] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n= nums.size();
        unordered_map<string,int>mp;
        return solve(nums,0,0,target,mp);
    }
};
