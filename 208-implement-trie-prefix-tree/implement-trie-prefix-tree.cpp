class TrieNode {
public:
	char data;
	TrieNode* children[26];
	bool isEndNode;
	TrieNode(char data) {
		this->data = data;
		isEndNode = false;

		for (int i = 0;i < 26;i++) {
			children[i] = NULL;
		}
	}
};
class Trie {
public:
	TrieNode* root;
	Trie() {
		root = new TrieNode('\0');
	}
	void insertRec(TrieNode* root, string word) {
		int leng = word.length();
		if (leng == 0) {
			root->isEndNode = true;
			return;
		}
		TrieNode* child;
		if (root->children[word[0]-'a'] != NULL) {
			child = root->children[word[0]-'a'];
		}
		else {
			child = new TrieNode(word[0]);
			root->children[word[0]-'a'] = child;
		}
		insertRec(child, word.substr(1));
	}

	void insert(string word) {
		insertRec(root, word);
	}

	bool searchRec(TrieNode* root, string word) {
		if (word.length() == 0) {
			return root->isEndNode;
		}
		if (root->children[word[0]-'a'] != NULL) {
			TrieNode* child = root->children[word[0]-'a'];
			return searchRec(child, word.substr(1));
		}
		else {
			return false;
		}
	}
	bool search(string word) {
		return searchRec(root, word);
	}
    bool startsWithRec(TrieNode* root,string prefix){
        
		if (prefix.length() == 0) {
			return true;
		}
		if (root->children[prefix[0]-'a'] != NULL) {
			TrieNode* child = root->children[prefix[0]-'a'];
			return startsWithRec(child, prefix.substr(1));
		}
		else {
			return false;
		}
        
    }
    bool startsWith(string prefix) {
        return startsWithRec(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */