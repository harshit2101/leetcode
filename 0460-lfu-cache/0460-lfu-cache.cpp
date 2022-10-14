class LFUCache {
public:
    int cap=0;
    int csize=0;

    struct Node{
        Node* prev=NULL;
        Node* next=NULL;
        int counter=0;
        int key;
        int val;
    };

    unordered_map<int,pair<int,Node*>> keyMp;
    map<int,pair<Node*,Node*>> countMp;

    Node* createNode(int key, int val){
        Node* node= new Node();
        node->key=key;
        node->val=val;
        node->counter=1;
        return node;
    }
    
    pair<Node*,Node*> createDLL(){
        Node* start= createNode(-1,-1);
        Node* end= createNode(-1,-1);
        start->next=end;
        end->prev=start;
        return {start,end};
    }

    LFUCache(int capacity) {
        cap=capacity;
    }

    void deleteNode(Node* start,Node* end){
        int key=end->prev->key;
        keyMp.erase(key);

        end->prev=end->prev->prev;
        end->prev->next=end;

    }
    void addNode(int cnt, Node* temp){
        if(countMp.find(cnt)==countMp.end()){
            pair<Node*,Node*> p = createDLL();
            countMp[cnt]=p;
        }
        Node* start= countMp[cnt].first;
        temp->next=start->next; 
        temp->prev=start;
        start->next->prev=temp;
        start->next=temp;   
    }
    void removeNode(int cnt,Node* temp){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        if(countMp[cnt].first->next==countMp[cnt].second)
            countMp.erase(cnt);
    }
    int get(int key){
        if(keyMp.find(key)!=keyMp.end()){
            int cnt=keyMp[key].first;
            Node* temp = keyMp[key].second;
            removeNode(temp->counter,temp);
            temp->counter++;
            addNode(temp->counter,temp);
            return temp->val;

        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap!=0){
            if(keyMp.find(key)==keyMp.end()){
                if(csize==cap){
                    deleteNode(countMp.begin()->second.first,countMp.begin()->second.second);
                    csize--;
                }
                Node* temp= createNode(key,value);
                keyMp[key]={1,temp};
                addNode(1,temp);
                csize++;
            }
            else{
                Node* temp= keyMp[key].second;
                temp->val=value;
                temp->counter++;
                keyMp[key]={temp->counter,temp};
                removeNode(temp->counter-1,temp);
                addNode(temp->counter,temp);
            }
        }
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */