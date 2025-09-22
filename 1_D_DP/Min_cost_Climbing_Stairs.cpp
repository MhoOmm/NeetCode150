// top down approach
#include<cstring>
class Solution {
public:
    int t[101];
    int solve(int i, int n ,vector<int>&cost)
    {
        if(i>=n)
        {
            return 0;
        }
        if(t[i]!=-1)
        {
            return t[i];
        }
        return t[i]=min((cost[i]+solve(i+1,n,cost)),(cost[i]+solve(i+2,n,cost)));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n  = cost.size();
        memset(t,-1,sizeof(t));
        return min(solve(0,n,cost),solve(1,n,cost));  
    }
};


// bottom up approach
#include<cstring>
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n  = cost.size();
        int t[101];
        t[0] = cost[0];
        t[1] = cost[1];

        for(int i = 2;i<=n;i++)
        {
            t[i] = cost[i] + min(t[i-1],t[i-2]);
        }

        return min(t[n-1],t[n-2]);  
    }
};
