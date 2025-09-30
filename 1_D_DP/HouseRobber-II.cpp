// recursion + memo
#include <cstring>
class Solution {
public:
    int t[101];
    int solve(int i,int n ,vector<int>& nums)
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
        int n= nums.size();

        if(n==0) return 0;
        if(n==1)return nums[0];

        memset(t,-1,sizeof(t));
        int case1 = solve(0,n-1,nums);
        memset(t,-1,sizeof(t));
        int case2 = solve(1,n,nums);

        return max(case1,case2);
    }
};

// bottom up 

class Solution {
public:
    int n;
    
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n == 1)
            return nums[0];
        
        vector<int> t(n+1, 0);
        
        int result1 = 0;
        int result2 = 0;
        t[0] = 0;
        for(int i = 1; i<=n-1; i++) {
            t[i] = max(t[i-1] , nums[i-1]+ ((i-2 >= 0) ? t[i-2] : 0 ));
        }
        result1 = t[n-1];
        
        t.clear();
        
        t[0] = 0;
        t[1] = 0;
        for(int i = 2; i<=n; i++) {
            t[i] = max(t[i-1] , nums[i-1]+ ((i-2 >= 0) ? t[i-2] : 0 ));
        }
        result2 = t[n];
        
        return max(result1, result2);
        
    }
};
