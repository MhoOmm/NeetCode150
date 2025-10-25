// Recursion + Memoization
#include <cstring>
class Solution {
public:
    int n;
    int t[100001];
    bool solve(int i,vector<int>& nums)
    {
        if(i>=n-1)
        {
            return true;
        }
        if(t[i]!=-1)
        {
            return t[i];
        }

        for(int count= 1;count<=nums[i];count++)
        {
           if(solve(i+count,nums) )
           {
            return t[i]=true;
           }
        }

        return t[i]=false;
    }
    bool canJump(vector<int>& nums) { 
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,nums);
    }
};


// Bottom up
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool>t(n,false);
        t[0]  = true;
        for(int i = 1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(t[j]==true && nums[j]+j >= i)
                {
                    t[i] = true;
                    break;
                }
            }
        }

        return t[n-1];
        
    }
};

// Smart Approach
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach =0;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(i>maxReach)
            {
                return false;
            }
            maxReach = max(maxReach,nums[i]+i);
        }
        return true;
    }
};
