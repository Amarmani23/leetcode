class WordDictionary {
private:
    struct TrieNode{
        TrieNode* child[26]= {nullptr};
        bool isEnd=false;
    };
    TrieNode* root;
    bool dfs(string word, int index, TrieNode* node){
        for(int i=index;i<word.length();i++){
            char c=word[i];
            if(c=='.'){
                for(int j=0;j<26;j++){
                    if(node->child[j]!=nullptr){
                        if(dfs(word,i+1,node->child[j])){
                            return true;
                        }
                    }
                }
                return false;
            }else {
                int idx=c-'a';
                if(node->child[idx]==nullptr){
                    return false;
                }
                node=node->child[idx];
            }
        }
        return node->isEnd;
    }
public:
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char &c:word){
            int idx=c-'a';
            if(node->child[idx]==nullptr){
                node->child[idx]=new TrieNode();
            }
            node=node->child[idx];
        }
        node->isEnd=true;

    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */