// Recursion + Memo
#include<cstring>
class Solution {
public:
    int t[1001][1001];
    bool check(int i ,int j,string &s)
    {
        if(i>j)return true;

        if(t[i][j]!=-1)
        {
            return t[i][j];
        }

        if(s[i]==s[j])return t[i][j] =check(i+1,j-1,s);

        return  t[i][j]=false;
    }
    string longestPalindrome(string s) {

        int n = s.length();
        if(n==1)
        {
            return s;
        }
        memset(t,-1,sizeof(t));
        string ans = s.substr(0,1);
        int maxLength = 1;
        for(int i=0;i<n;i++){
            for(int j = i;j<n ;j++)
            {
                if(check(i,j,s)){
                    int l = (j-i+1);
                    if(l>maxLength){
                        maxLength = l;
                        ans = s.substr(i,l);
                    }
                }
            }
        }

        return ans;   
    }
};


// Bottom Up

class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.length();
        
        vector<vector<bool>>t(n,vector<bool>(n,false));

        int maxl = 1;
        string ans = s.substr(0,1);

        for(int l=1;l<=n;l++)
        {
            for(int i =0;i+l-1<n;i++)
            {
                int j=i+l-1 ;

                if(i==j)t[i][j]=true;

                else if(i+1==j)t[i][j]=(s[i]==s[j]);

                else{
                    t[i][j] = (s[i]==s[j] && t[i+1][j-1]);
                }

                if(t[i][j])
                {
                    int len = j-i+1;
                    if(len>maxl)
                    {
                        ans = s.substr(i,len);
                        maxl = len;
                    }
                }
            }
        }

        return ans;
        
    }
};
