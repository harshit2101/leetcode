//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(vector<string>& ans, string temp, vector<vector<int>>& vis, int dr[], int dc[], int i, int j, vector<vector<int>>& m, int n){
        if(i==n-1 &&j==n-1){
            ans.push_back(temp);
            return;
        }
        
        string dir="DLRU";
        
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            
            if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc] && m[nr][nc]==1){
                vis[i][j]=1;
                solve(ans,temp+dir[k],vis,dr,dc,nr,nc,m,n);
                vis[i][j]=0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string temp;
        vector<vector<int>> vis(n,vector<int>(n,0));
        int dr[]={1,0,0,-1};
        int dc[]={0,-1,1,0};
        
        if(m[0][0]==1) solve(ans,temp,vis,dr,dc,0,0,m,n);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends