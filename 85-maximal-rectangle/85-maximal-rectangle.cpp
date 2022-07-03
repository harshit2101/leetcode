class Solution {
    
public:
    vector<int> nextSmallerRight(vector<int> heights, int n){
        vector<int> res(n);
        stack<int> st;
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty()){
                res[i] = -1;
            }
            else{
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
        
    }
    vector<int> nextSmallerLeft(vector<int> heights, int n){
        vector<int> res(n);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty()){
                res[i] = -1;
            }
            else{
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
        
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> leftSmaller(n), rightSmaller(n);
        
        rightSmaller = nextSmallerRight(heights,n);
        leftSmaller = nextSmallerLeft(heights,n);

        
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++){
            int left = leftSmaller[i];
            int right = rightSmaller[i];
            int  w;
            
            if(left==-1) left = -1;
            if(right==-1) right = n;
            
            w = (right-1)-(left+1)+1;
            ans = max(ans,heights[i]*w);
        }
        
        
        return ans;
    }


public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size(), result=0;
        vector<int> histogram(n, 0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1')
                    histogram[j]+=1;
                else
                    histogram[j]=0;
            }
            
            result = max(result, largestRectangleArea(histogram));
            cout<<result<<" ";
        }
        return result;
    }
};