class Solution {
public:
    int parent[26];
    int rank[26];
    
    int find(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = find(parent[node]);
    }
    
    void Union(int a, int b){
        
        a = find(a);
        b = find(b);
        
        if(rank[a]<rank[b]) parent[a]=b;
        else if(rank[a]>rank[b]) parent[b]=a;
        else{
            parent[b]=a;
            rank[a]++;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<26;i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        for(auto x : equations){
            if(x[1] == '=')
                Union(x[0]-'a', x[3]-'a');
        }
                
        for(auto x : equations){

            if(x[1] == '!'){
                int a = find(x[0]-'a');
                int b = find(x[3]-'a');
                
                if(a == b){
                    return false;
                }
            }
        }
        
        return true;
    }
};