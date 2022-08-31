class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i = 0 ; i < n ; i++){
            dfs(board,i,0);
            dfs(board,i,m-1);
        }
        for(int j = 0 ; j < m ; j++){
            dfs(board,0,j);
            dfs(board,n-1,j);
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j]=='V')board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int r, int c){
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size())return;
        if(board[r][c]!='O')return;
        board[r][c] = 'V';
        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
        dfs(board, r, c-1);
    }
};