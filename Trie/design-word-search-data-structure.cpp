class WordDictionary {
public:
    struct trie{
        trie* child[26];
        int eow ;
    };
    trie* root;
    trie* getNode()
    {
        trie* newn = new trie();
        newn->eow = false;
        for(int i=0;i<26;i++)
        {
            newn->child[i] = NULL;
        }
        return newn;
    }
    WordDictionary() {
        root = getNode();
    }
    
    void addWord(string word) {
        trie* crawl = root;
        for(int i=0;i<word.length();i++)
        {
            int idx = word[i]-'a';
            if(crawl->child[idx] == NULL)
            {
                crawl->child[idx] = getNode();
            }
            crawl= crawl->child[idx];
        }
        crawl->eow = true;
    }

    bool searchrecur(string word, trie* node)
    {
        trie* crawl = node;
        for(int i =0;i<word.length();i++)
        {
            char ch = word[i];
            if(ch=='.')
            {
                for(int j=0;j<26;j++)
                {
                    if(crawl->child[j]!=NULL)
                    {
                        if(searchrecur(word.substr(i+1),crawl->child[j])){
                            return true;
                        }
                    }
                }

                return false;

            }else if(crawl->child[ch-'a'] == NULL)
            {
                return false;
            }

            crawl  = crawl->child[ch-'a'];
        }
        return (crawl != NULL && crawl->eow==true);
    }
    
    bool search(string word) {
        return searchrecur(word,root);
    }
};

