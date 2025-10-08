// Recursion + Memoization
#include<cstring>
class Solution {
public:
    int t[101][101];
    int solve(int i ,int j,int m,int n)
    {
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        if(i<0||i>=m||j>=n||j<0)
        {
            return 0;
        }
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        int right = solve(i,j+1,m,n);
        int down  = solve(i+1,j,m,n);

        return t[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        memset(t,-1,sizeof(t));
        return solve(0,0,m,n); 
    }
};

// Bottom Up 

class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>>t(m+1,vector<int>(n+1,0));
        for(int i = 0;i<m;i++)
        {
            t[i][0] = 1;
        }
        for(int j= 0;j<n;j++)
        {
            t[0][j] = 1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                t[i][j] = t[i-1][j]+t[i][j-1];
            }
        }

        return t[m-1][n-1];
        
    }
};
