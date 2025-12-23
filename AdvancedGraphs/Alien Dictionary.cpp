class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        int size = words.size();
        // making adjacnency list;
        vector<int> inDeg(26, 0);
        vector<bool> present(26, false);

        for(auto &word:words)
        {
            for(auto &ch:word)
            {
                present[ch-'a']=true;
            }
        }

        for(int i =0;i<size-1;i++)
        {
            string str1 = words[i];
            string str2 = words[i+1];
            int n = str1.length();
            int m = str2.length();
            int k = min(n,m);
            if (str1.size() > str2.size() && str1.substr(0, str2.size()) == str2) {
                return "";
            }
            for(int j=0;j<k;j++)
            {

                if(str1[j]!=str2[j])
                {
                    adj[str1[j] - 'a'].push_back(str2[j] - 'a');
                    inDeg[str2[j]-'a']++;
                    break;
                }
            }
        }
        string result="";
        queue<int>q;
        for(int i=0;i<26;i++)
        {
            if(present[i] && inDeg[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            result.push_back(u+'a');
            for(auto &neig:adj[u])
            {
                inDeg[neig]--;
                if(inDeg[neig]==0)
                {
                    q.push(neig);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (present[i]) count++;
        }

        if (result.size() != count)
            return "";


        return result;
    }
};
