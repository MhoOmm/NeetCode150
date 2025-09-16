// with sorting
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>mp;
        for(auto &str :strs)
        {
            string temp = str;
            sort(begin(temp),end(temp));
            mp[temp].push_back(str);
        }

        vector<vector<string>>result;

        for(auto &it:mp)
        {
            result.push_back(it.second);
        }

        return result;
    }
};


// without sorting
class Solution {
public:

    string solve(string st){

        vector<int>freq(26,0);
        for(auto &s:st)
        {
            freq[s-'a']++;
        }

        string news;

        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
            {
                news+=string(freq[i],i+'a');
            }
        }

        return news;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>mp;
        for(auto &str :strs)
        {
            string temp = solve(str);
            mp[temp].push_back(str);
        }

        vector<vector<string>>result;

        for(auto &it:mp)
        {
            result.push_back(it.second);
        }

        return result;
    }
};

