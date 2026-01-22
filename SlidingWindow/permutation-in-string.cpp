class Solution {
public:
    bool ispermute(string &s1,string &comp)
    {
        vector<int>freq(26,0);
        for(int i =0;i<s1.length();i++)
        {
            freq[s1[i]-'a'] ++;
        }
        for(int i=0;i<comp.length();i++)
        {
            freq[comp[i]-'a'] --;
        }

        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s2.length();
        int c = s1.length();

        int i=0 ;
        int j=0;

        while(j<n)
        {
            while(j-i+1 > c)
            {
                i++;
            }
            string comp = s2.substr(i,j-i+1);
            if((j-i+1 == c) && ispermute(s1,comp))
            {
                return true;
            }
            j++;
        }

        return false;
    }
};


// better apporach
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.length();
        int c = s1.length();

        if (c > n) return false;

        vector<int> freq1(26, 0), freq2(26, 0);
        for (int i = 0; i < c; i++) {
            freq1[s1[i]-'a']++;
        }

        int i = 0;
        for (int j = 0; j < n; j++) {
            freq2[s2[j] - 'a']++;
            if (j-i+1 > c) {
                freq2[s2[i] - 'a']--;
                i++;
            }

            if (freq1 == freq2) {
                return true;
            }
        }

        return false;
    }
};
