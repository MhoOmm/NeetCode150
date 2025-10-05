// Recursion and Memoization
#include <cstring>
class Solution {
public:

    int n,m;
    int t[101][101];
    int solve(int i,int j,string &s1, string &s2)
    {
        if(i==n)
        {
            return m-j;//insertions;
        }

        if(j==m)
        {
            return n-i;//deletions;
        }
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }

        if(s1[i]==s2[j])
        {
            return t[i][j]=solve(i+1,j+1,s1,s2);
        }else{

            int insert =1+ solve(i,j+1,s1,s2);
            int del = 1+solve(i+1,j,s1,s2);
            int update =1+ solve(i+1,j+1,s1,s2);

            return t[i][j] = min({insert,del,update});
        }
    }
    int minDistance(string s1, string s2) {  
        n = s1.length();
        m = s2.length();

        memset(t,-1,sizeof(t));

        return solve(0,0,s1,s2);    
    }
};


// Bottom Up Approach
class Solution {
public:
    int minDistance(string s1, string s2) {

        int n = s1.length();
        int m = s2.length();

        vector<vector<int>>t (n+1,vector<int>(m+1));

        for(int i=0 ;i<=n;i++)
        {
            for(int j =0;j<=m;j++)
            {
                if (i == 0) {
                    t[i][j] = j;
                } else if (j == 0) {
                    t[i][j] = i;
                } else if(s1[i-1]==s2[j-1])
                {
                    t[i][j] = t[i-1][j-1];
                }
                else{
                    t[i][j] = 1+ min({t[i][j-1],t[i-1][j],t[i-1][j-1]});
                }
            }
        }

        return t[n][m];
        
    }
};

