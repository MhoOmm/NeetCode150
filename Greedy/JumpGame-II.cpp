// Top Down - Apporach (Dp)
#include <cstring>
class Solution {
public:
    int n ;
    int t[1001];
    int solve(int i,vector<int>& nums){
        if(i>=n-1)
        {
            return 0;
        }
        if(t[i]!=-1){
            return t[i];
        }
        int minJ = INT_MAX;;

        for(int idx = 1;idx<=nums[i];idx++)
        {
           int next = i+idx;
           int steps =solve(i+idx,nums);
           if(steps!=INT_MAX){
            minJ = min(minJ,steps+1);
           }
           
        }

        return t[i] = minJ;

    }

    int jump(vector<int>& nums) {

        n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,nums);
        
    }
};


// Bottom up Approach (DP)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int>t(n,INT_MAX);
        t[0] = 0;

        for(int i = 0; i<n;i++)
        {
            if (t[i]==INT_MAX){
                continue;
            }
            for(int j = i+1;j<=min(n - 1, i + nums[i]);j++)
            {
                t[j] = min(t[j],t[i]+1);
            }
        }

        return t[n-1];
        
    }
};

// greedy approach

class Solution {
public:
    int jump(vector<int>& nums) {
        int l= 0;
        int r = 0;
        int n= nums.size();
        int jumps=0;
        while(r<n-1)
        {
            int farthest  = 0;
            for(int i = l;i<=r;i++)
            {
                farthest = max(farthest,i+nums[i]);
            }
            l = r+1;
            r = farthest;
            jumps+=1;
        }

        return jumps;
        
        
    }
};
