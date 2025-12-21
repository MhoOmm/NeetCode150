class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<string>q;
        int n = beginWord.length();
        int level=1;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        unordered_set<string>visited;
        visited.insert(beginWord);
        if(beginWord==endWord)
        {
            return 0;
        }
        q.push(beginWord);

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                string top = q.front();
                q.pop();

                if(top == endWord)
                {
                    return level;
                }
                string temp = top;
                for(char ch: "abcdefghijklmnopqrstuvwxyz"){
                    for(int i=0;i<n;i++)
                    {
                        char org = temp[i];
                        if(org == ch)continue;
                        temp[i] = ch;
                        if(dict.count(temp) && !visited.count(temp)){
                            q.push(temp);
                            visited.insert(temp);
                        }
                        temp[i] = org;
                    }
                }
            }
            level++;
        }
        return 0;  
        
    }
};