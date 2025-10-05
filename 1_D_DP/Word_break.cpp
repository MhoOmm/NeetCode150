#include <cstring>

class Solution {
public:
    int n;
    int t[201];
    unordered_set<string> st;

    bool solve(int i, string &s) {
        if (i == n) return true; 

        if (t[i] != -1) return t[i];

        for (int l = 1; l <= n - i; l++) {
            string temp = s.substr(i, l);
            if (st.find(temp) != st.end() && solve(i + l, s)) {
                return t[i] = 1;
            }
        }

        return t[i] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(t, -1, sizeof(t));
        st.clear();
        for (auto &str : wordDict) st.insert(str);

        return solve(0, s);
    }
};
