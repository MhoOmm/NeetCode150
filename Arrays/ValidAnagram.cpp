class Solution {
public:
    bool isAnagram(string s, string t) {

        int n = s.length();
        int m = t.length();
        
        if(n!=m)
        {
            return false;
        }
        vector<int>mps(26,0);
        vector<int>mpt(26,0);
        for(int i = 0;i<n;i++)
        {
            mps[s[i] -'a']++;
            mpt[t[i] -'a']++;
        }

        for(int i =0;i<26;i++)
        {
            if(mps[i]!=mpt[i])
            {
                return false;
            }
        }

        return true;   
    }
};
