

class Trie {
    #define max_nodes 10000
    struct TrieNode{
        char val;
        int count, ends_here;
        TrieNode *child[26]; 
    };
    TrieNode *root;
    TrieNode *getNode(int index){
        TrieNode *node = new TrieNode;
        node -> val = 'a' + index;
        node -> count = node -> ends_here = 0;
        for(int i=0;i<26;i++){
            node->child[i] = NULL;
        }
        return node;
    }
public:
    /** Initialize your data structure here. */
    Trie() { 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root = getNode('/'-'a');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        int index;
        for(int i=0;i<word.size();i++){
            index = word[i] - 'a';
            if(curr->child[index]==NULL){
                curr -> child[index] = getNode(index);
            }
            curr->child[index]->count += 1;
            curr = curr ->child[index];
        }
        curr->ends_here +=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        int index;
        for(int i=0;i<word.size();i++){
            index = word[i] - 'a';
            if(curr->child[index]==NULL){
                return false;
            }
            curr = curr->child[index];
        }
        return (curr->ends_here >0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int index;
        for(int i=0;i<prefix.size();i++){
            index = prefix[i] - 'a';
            if(curr->child[index]==NULL){
                return false;
            }
            curr = curr->child[index];
        }
        return (curr->count >0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

