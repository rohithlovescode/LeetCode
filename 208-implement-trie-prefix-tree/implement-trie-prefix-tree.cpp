class TrieNode{
public:
    char data;
    TrieNode* child[26];
    bool isTerminal;
    TrieNode(char data){
        this->data=data;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        isTerminal=false;
    }
    
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode('~');
    }
    
    void insert(string word) {
        TrieNode* temp=root;
        int i;
        for(i=0;i<word.size();i++){
            char ch=word[i];
            if(temp->child[ch-'a']==nullptr){
                break;
            }
            temp=temp->child[ch-'a'];
        }
        for(;i<word.size();i++){
            char ch=word[i];
            temp->child[ch-'a']=new TrieNode(ch);
            temp=temp->child[ch-'a'];
        }
        temp->isTerminal=true;
    }
    
    bool search(string word) {
        TrieNode* temp=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(temp->child[ch-'a']==nullptr){
                return false;
            }
            temp=temp->child[ch-'a'];
        }
        if(temp->isTerminal==true){
            return true;
        }
        return false;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp=root;
        for(int i=0;i<prefix.size();i++){
            char ch=prefix[i];
            if(temp->child[ch-'a']==nullptr){
                return false;
            }
            temp=temp->child[ch-'a'];
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */