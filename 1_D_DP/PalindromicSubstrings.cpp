// Recursion 
class Solution {
public:

    bool check(int i,int j,string &s)
    {
        if(i>j)return true;

        if(s[i]==s[j]){
            return check(i+1,j-1,s);
        }

        return false;
    }
    int countSubstrings(string s) {

        int n = s.length();

        int count = 0;

        for(int i=0 ;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(check(i,j,s))
                {
                    count++;
                }
            }
        }

        return count;
        
    }
};


// Memoization

#include <cstring>

class Solution {
public:
    int t[1001][1001];
    bool check(int i,int j,string &s)
    {
        if(i>j)return true;
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }

        if(s[i]==s[j]){
            return check(i+1,j-1,s);
        }

        return false;
    }
    int countSubstrings(string s) {

        int n = s.length();

        int count = 0;

        memset(t,-1,sizeof(t));

        for(int i=0 ;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(check(i,j,s))
                {
                    count++;
                }
            }
        }

        return count;
        
    }
};

// Bottom Up (Blueprint)

class Solution {
public:
    int countSubstrings(string s) {

        int n = s.length();

        vector<vector<bool>>t(n,vector<bool>(n,false));
        int count = 0;

        for(int l = 1; l <= n; l++)
        {
            for(int i =0;i+l-1<n;i++)
            {
                int j = i+l-1;
                if(i==j)
                {
                    t[i][j]=true;
                }else if(i+1 == j)
                {
                    t[i][j]= (s[i]==s[j]);
                }else{
                    t[i][j] = (s[i]==s[j] && t[i+1][j-1]);
                }

                if(t[i][j])
                {
                    count++;
                }
            }
        }


        return count;
        
    }
};

