class node{
    public:
    node* links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    void put(char ch, node* newn){
        links[ch-'a'] = newn;
    }
    
    node* get(char ch){
        return links[ch-'a'];
    }
    
    void markEnd(){
        flag = true;
    }
    
    bool getEnd(){
        return flag;
    }
};

class Trie {
public:
    node* root;
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* temp = root;
        for (int i=0; i<word.size(); i++){
            // if doesnt contains
            if (!temp->containsKey(word[i])){
                temp->put(word[i], new node());
            }
            // move to next
            temp = temp->get(word[i]);
        }
        temp->markEnd();
    }
    
    bool search(string word) {
        node* temp = root;
        for (int i=0; i<word.size(); i++){
            if (!temp->containsKey(word[i])){
                return false;
            }
            temp = temp->get(word[i]);
        }
        return (temp->getEnd());
    }
    
    bool startsWith(string word) {
        node* temp = root;
        for (int i=0; i<word.size(); i++){
            if (!temp->containsKey(word[i])){
                return false;
            }
            temp = temp->get(word[i]);
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