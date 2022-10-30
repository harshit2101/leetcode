class Solution {
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        if (grid[0][0] == 1) return -1;
        int n = grid.size(), m = grid[0].size();
        
        if (k >= m+n-2) return m+n-2;
        
        vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));
        queue<vector<int>> q;
        q.push({0, 0, 0});
        visited[0][0][0] = 1;
        int dist = 0, minDist = INT_MAX;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int r = q.front()[0], c = q.front()[1], obs = q.front()[2];
                q.pop();

                if (r == n - 1 && c == m - 1) {
                    return dist;
                }

                for(int i = 0; i < 4; i++) {
                    int nr = r + dr[i], nc = c + dc[i];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                    if (obs + grid[nr][nc] > k || visited[nr][nc][obs + grid[nr][nc]]) continue;

                    q.push({nr, nc, obs + grid[nr][nc]});
                    visited[nr][nc][obs + grid[nr][nc]] = 1;
                }
            }
            
            dist++;
        }
        
        return minDist == INT_MAX ? -1 : minDist;
    }
};