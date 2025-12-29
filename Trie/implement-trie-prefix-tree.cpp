class PrefixTree {
public: 
    // MAKING THE DATASTRUCTURE
    struct trieNode {
        bool eow;
        trieNode *children[26];
    };
    // making a new node
    trieNode* getNode(){
        trieNode* newn = new trieNode();
        newn -> eow = false;
        for(int i=0;i<26;i++)
        {
            newn->children[i] = NULL;
        }
        return newn;
    }

    trieNode* root;// Init node
    // constructor
    PrefixTree() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode *crawl = root;
        for(auto &ch:word)
        {
            int idx = ch-'a';
            if(crawl->children[idx] == NULL)
            {
                crawl->children[idx] = getNode();
            }
            crawl = crawl->children[idx];
        }
        crawl->eow  = true;
    }
    
    bool search(string word) {
        trieNode *crawl = root;
        for(auto &ch:word)
        {
            int idx = ch-'a';
            if(crawl->children[idx] == NULL)
            {
                return false;
            }
            crawl = crawl->children[idx];
        }
        return (crawl != NULL && crawl->eow  == true);
    }
    
    bool startsWith(string prefix) {
        trieNode *crawl = root;
        int n = prefix.length();
        int i = 0;
        for(auto &ch:prefix)
        {
            int idx = ch-'a';
            if(crawl->children[idx] == NULL)
            {
                return false;
            }
            crawl = crawl->children[idx];
            i++;
        }
        return (i==n); 
    }
};


