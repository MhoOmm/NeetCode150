// recursion + memo
// O(n)
#include <cstring>
class Solution {
public:

    int t[31];

    int solve(int n)
    {
        if(n<=1)
        {
            return 1;
        }
        if(t[n]!=-1)
        {
            return t[n];
        }
        return t[n]=solve(n-1)+solve(n-2);
    }
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);      
    }
};

// bottom up o(n)

class Solution {
public:
    int climbStairs(int n) {
        int t[31];
        t[1] = 1;
        t[2]  = 2;
        for(int i=3;i<=n;i++)
        {
            t[i] = t[i-1]+t[i-2];
        } 
        return t[n];      
    }
};

