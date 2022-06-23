class Solution {
public:
    
    static bool comp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(),courses.end(),comp);
        
        priority_queue<int> pq;
        int time=0;
        
        for(auto c:courses){
            if(time+c[0]<=c[1]){
                time+=c[0];
                pq.push(c[0]);
            }
            
            else if(!pq.empty() && pq.top()>=c[0]){
                time=time-pq.top()+c[0];
                pq.pop();
                pq.push(c[0]);
            }
        }
        
        return pq.size();
    }
};