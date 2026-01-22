class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxL = 0;
        vector<int>freq(256,0);
        int i =0;
        int j =0;
        while(j<n)
        {
            freq[s[j]]++;
            while(freq[s[j]]>1)
            {
                freq[s[i]]--;
                i++;
            }
            maxL = max(maxL, j-i+1);
            j++;
        }

        return maxL;
    }
};
