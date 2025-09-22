// top Down Approach
#include <cstring>
class Solution {
public:
    int t[101];
    int solve(int i,int n,vector<int>&nums)
    {
        if(i>=n)
        {
            return 0;
        }
        if(t[i]!=-1)
        {
            return t[i];
        }

        int take = nums[i]+solve(i+2,n,nums);
        int skip = solve(i+1,n,nums);

        return t[i] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,n,nums); 
    }
};

// bottom up Approach

#include <cstring>
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int t[n+1];
        if(n==0)return 0;
        if(n==2) return max(nums[0],nums[1]);
        if(n==1) return nums[0];
        t[0] = nums[0];
        t[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            t[i] = max((nums[i]+t[i-2]),t[i-1]);
        }
        
        return t[n-1]; 
    }
};
