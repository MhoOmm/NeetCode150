class Solution {
public:
    int n ,m,o;
    int t[101][101][201];
    bool solve(int i,int j,int k,string &s1,string&s2,string&s3)
    {
        if(i==n && j==m && k==m+n)
        {
            return true;
        }
        if(k>=o){
            return false;
        }
        if(t[i][j][k]!=-1)return t[i][j][k];

        bool result = false;

        if(i<n && s1[i]==s3[k])
        {
            result = solve(i+1,j,k+1,s1,s2,s3); 
        }

        if(result)return t[i][j][k] = true;

        if(j<m && s2[j]==s3[k])
        {
            result  = solve(i,j+1,k+1,s1,s2,s3);
        }

        return t[i][j][k] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n  = s1.length();
        m = s2.length();
        o = s3.length();
        if(m+n != o)return false;
        memset(t,-1,sizeof(t));
        return solve(0,0,0,s1,s2,s3);   
    }
};