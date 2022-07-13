struct Node {
    bool f = false;
    Node* p[26];
    Node() {
        for (int i=0; i<26; i++)
            p[i] = nullptr;
    }
    
    bool in(char c) {
        return p[c - 'a'] != nullptr;
    }
    
    void insert(char c) {
        if (!in(c))
            p[c - 'a'] = new Node();
    }
    
    Node* get(char c) {
        return p[c - 'a'];
    }
};

class WordDictionary {
    Node* n;
public:
    WordDictionary() {
        n = new Node();
    }
    
    void addWord(string word) {
        Node *p = n;
        for (auto k: word) {
            if (!p->in(k)) {
                p->insert(k);
            }
            p = p->get(k);
        }
        p->f = true;
    }
    
    bool find(string &s, int i, Node* p) {
        if (i == s.size()) {            
            return p->f;
        }

        if (s[i] != '.') {
            if (p->in(s[i]))
                return find(s, i+1, p->get(s[i]));
            return false;
        }
        
        for (int j=0; j<26; j++) {
            if (p->p[j] != nullptr)
                if (find(s, i+1, p->p[j]))
                    return true;
        }
        
        return false;
    }
    
    bool search(string word) {
        return find(word, 0, n);
    }
};



/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */