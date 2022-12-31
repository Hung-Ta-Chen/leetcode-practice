class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;
        int path_len = 0;
        # BFS
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        visited[0][0] = true;
        while(!q.empty()){
            # Maintain the size of queue as the size of level for better time complexity
            int lvl_size = q.size();
            path_len++;
            for(int k = 0; k < lvl_size; k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                # Reach the endpoint
                if(i == m-1 && j == n-1) return path_len; 
                # Push the unvisited neighbors into the queue
                if(i != 0 && j != 0 && grid[i-1][j-1] == 0 && !visited[i-1][j-1]){
                    q.push(make_pair(i-1, j-1));
                    visited[i-1][j-1] = true;
                }
                if(i != 0 && j != n-1 && grid[i-1][j+1] == 0 && !visited[i-1][j+1]){
                    q.push(make_pair(i-1, j+1));
                    visited[i-1][j+1] = true;
                }
                if(i != 0 && grid[i-1][j] == 0 && !visited[i-1][j]){
                    q.push(make_pair(i-1, j));
                    visited[i-1][j] = true;
                }
                if(i != m-1 && j != 0 && grid[i+1][j-1] == 0 && !visited[i+1][j-1]){
                    q.push(make_pair(i+1, j-1));
                    visited[i+1][j-1] = true;
                }
                if(i != m-1 && j != n-1 && grid[i+1][j+1] == 0 && !visited[i+1][j+1]){
                    q.push(make_pair(i+1, j+1));
                    visited[i+1][j+1] = true;
                }
                if(i != m-1 && grid[i+1][j] == 0 && !visited[i+1][j]){
                    q.push(make_pair(i+1, j));
                    visited[i+1][j] = true;
                }
                if(j != 0 && grid[i][j-1] == 0 && !visited[i][j-1]){
                    q.push(make_pair(i, j-1));
                    visited[i][j-1] = true;
                }
                if(j != n-1 && grid[i][j+1] == 0 && !visited[i][j+1]){
                    q.push(make_pair(i, j+1));
                    visited[i][j+1] = true;
                }
            }
        }
        return -1;       
    }
};
