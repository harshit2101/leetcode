class Solution {
public:
    vector<int> row={0,0,-1,1};
    vector<int> col={-1,1,0,0};
    void dfs(vector<vector<int>>& image, int sr, int sc,int n,int m, int color,int val)
    {
        image[sr][sc]=color;
        for(int i=0;i<4;i++)
        {
            int sr_new=sr-row[i];
            int sc_new=sc-col[i];
        if(sr_new>=0 && sr_new<n && sc_new>=0 && sc_new<m && image[sr_new][sc_new]==val && image[sr_new][sc_new]!=color)
        {
            dfs(image,sr_new,sc_new,n,m,color,val);
        }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r=image.size();
        int c=image[0].size();
        int val=image[sr][sc];
        dfs(image,sr,sc,r,c,color,val);
        return image;
    }
};