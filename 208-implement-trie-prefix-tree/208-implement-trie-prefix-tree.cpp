struct Node {
    Node* link[26];
    bool flag=false;
    // check if reference trie is present or not
    bool containKey(char ch){ 
        return (link[ch-'a']!=NULL);
    }
    // create a new reference trie
    void createKey (char ch, Node* node){
        link[ch-'a']=node;
    }
    // get the next reference trie
    Node* next(char ch){
        return link[ch-'a'];
    }
    // set flag true at the last reference of trie
    void setEnd(){
        flag=true;
    }
    // check whether the word is terminated or not 
    bool isEnd(){
        return flag;
    }
};

class Trie {
    Node* root;
public:
    // call constructor to create a new object
    Trie() {
        root= new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(auto& ch: word){
            // check if the current character is present on current trie node or not
            if(!node->containKey(ch)){ // if not, create a new reference trie
                node->createKey(ch, new Node());
            }
            node=node->next(ch); // move to the current node's reference trie
        }
        node->setEnd(); // set the word terminated
    }
    
    bool search(string word) {
        Node* node=root;
        for(auto& ch:word){
            // check if the current character is present on current trie node or not
            if(!node->containKey(ch)) return false; // if not, return false
            node=node->next(ch); // else move to the next reference trie
        }
        return node->isEnd(); // check the word terminated or not, if yes return true else false
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(auto& ch:prefix){
            // check if the current prefix character is present on current trie node or not
            if(!node->containKey(ch)) return false; // if not, return false
            node=node->next(ch); // else move to the next reference trie
        }
        return true; // not required to check the termination
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */