class Solution {
public:
    bool isPalindrome(string str) {

        string s;
        
        
        for(char c : str) {
            if(isalnum(c)) {
                s.push_back(tolower(c));
            }
        }

        int i= 0;
        int j = s.length()-1;

        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};