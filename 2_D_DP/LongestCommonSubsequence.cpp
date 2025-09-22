// recursion
#include<cstring>
class Solution {
public:
    int n,m;
    int t[1001][1001];
    int solve(int i,int j,string &text1, string &text2)
    {
        if(i>=n || j>=m)
        {
            return 0;
        }

        if(t[i][j]!=-1)
        {
            return t[i][j];
        }

        if(text1[i]==text2[j])
        {
            return  t[i][j]=1+solve(i+1,j+1,text1,text2);
        }else{
            return  t[i][j]=max(solve(i+1,j,text1,text2),solve(i,j+1,text1,text2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();
        memset(t,-1,sizeof(t));
        return solve(0,0,text1,text2);
    }
};

// bottom up 
#include<cstring>
class Solution {
public:
    int n,m;
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();
        int t[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            t[i][0]=0;
        }
        for(int i=0;i<=m;i++)
        {
            t[0][i] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])
                {
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]= max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        return t[n][m];
    }
};
