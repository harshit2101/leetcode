class Node {
   public:
    int key;
    int value;
    Node* pre;
    Node* next;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->pre = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
   private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void remove(Node* n) {
        Node* nPre = n->pre;
        Node* nNext = n->next;
        nPre->next = nNext;
        nNext->pre = nPre;
    }

    void insert(Node* n) {
        Node* first = head->next;
        head->next = n;
        n->pre = head;
        n->next = first;
        first->pre = n;
    }

   public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        Node* n = cache[key];
        remove(n);
        insert(n);

        return n->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }

        Node* n = new Node(key, value);
        insert(n);
        cache[key] = n;

        if (cache.size() > capacity) {
            Node* t = tail->pre;
            cache.erase(t->key);
            remove(t);
            delete(t);
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */