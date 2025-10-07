#include<cstring>
class Solution {
public:
    int t[101];
    int solve(int i,string &s,int &n)
    {
        if(i==n)
        {
            return 1;
        }

        if(s[i]=='0')
        {
            return 0;
        }

        if(t[i]!=-1)return t[i];

        int result = solve(i+1,s,n);

        if(i+1<n)
        {
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))
            {
                result+=solve(i+2,s,n);
            }
        }

        return t[i] = result;
    }
    int numDecodings(string s) {

        int n = s.length();
        memset(t,-1,sizeof(t));
        return solve(0,s,n);  
    }
};


// bottom up
class Solution {
public:
    int bottom_up_2(string&s, int n) {
        vector<int> t(n+1, 0);
        //t[i] = ways to decode string of length i
        t[0] = 1;
        t[1] = s[0]=='0'?0:1;
        
        for(int i = 2; i<=n; i++) {            
            if(s[i-1] != '0')
                t[i] += t[i-1];
                
            if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7'))
                t[i] += t[i-2];
            
        }
        return t[n];
    }
    
    int numDecodings(string &s) {
        int n = s.length();
        vector<int> t(n+1, -1);
        return bottom_up_2(s, n);
    }
};