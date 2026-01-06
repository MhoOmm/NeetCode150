class Solution {
public: 
    vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};
    int m,n;
    vector<string>result;
    struct trie{
        bool eow;
        trie* child[26];
        string word;
    };
    trie* getNode(){
        trie* newn = new trie();
        newn->eow = false;
        newn->word="";
        for(int i=0;i<26;i++)
        {
            newn->child[i] = NULL;
        }
        return newn;
    }
    void insert(trie* root,string input){
        trie* crawl = root;
        for(int i=0;i<input.length();i++)
        {
            int idx = input[i]-'a';
            if(crawl->child[idx] == NULL){
                crawl->child[idx] = getNode();
            }
            crawl  = crawl->child[idx];
        }
        crawl->eow = true;
        crawl->word = input;
    }

    void dfs(int i,int j,trie* root,vector<vector<char>>& board)
    {
        if(i>=m||j>=n||i<0||j<0||board[i][j]=='1'||root->child[board[i][j]-'a'] == NULL ){
            return;
        }
        root = root->child[board[i][j] - 'a'];
        if(root->eow == true)
        {
            result.push_back(root->word);
            root->eow = false; // to prevent duplicate entry in the result array
        }
        char temp = board[i][j];
        board[i][j] = '1';
        for(auto &dir:directions)
        {
            int ni = i+ dir[0];
            int nj = j+ dir[1];
            dfs(ni,nj,root,board);
        } 
        board[i][j]= temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        trie* root = getNode();

        for(int i=0;i<words.size();i++)
        {
            insert(root,words[i]);
        }
        for(int i =0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                char ch = board[i][j];
                if(root->child[ch-'a'] != NULL)
                {
                    dfs(i,j,root,board);
                }
            }
        }

        return result;
    }
};