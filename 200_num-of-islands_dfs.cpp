class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;
        # DFS
        stack<pair<int, int>> s;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] == 0 && grid[i][j] == '1'){
                    s.push(make_pair(i, j));
                    visited[i][j] = 1;
                    while(!s.empty()){
                        int curr_i = s.top().first;
                        int curr_j = s.top().second;
                        s.pop();
                        if(curr_i != 0 && grid[curr_i-1][curr_j] == '1' && visited[curr_i-1][curr_j] != 1){
                            s.push(make_pair(curr_i-1, curr_j));
                            visited[curr_i-1][curr_j] = 1;
                        }
                        if(curr_i != m-1 && grid[curr_i+1][curr_j] == '1' && visited[curr_i+1][curr_j] != 1){
                            s.push(make_pair(curr_i+1, curr_j));
                            visited[curr_i+1][curr_j] = 1;
                        }
                        if(curr_j != 0 && grid[curr_i][curr_j-1] == '1' && visited[curr_i][curr_j-1] != 1){
                            s.push(make_pair(curr_i, curr_j-1));
                            visited[curr_i][curr_j-1] = 1;
                        }
                        if(curr_j != n-1 && grid[curr_i][curr_j+1] == '1' && visited[curr_i][curr_j+1] != 1){
                            s.push(make_pair(curr_i, curr_j+1));
                            visited[curr_i][curr_j+1] = 1;
                        }
                    }
                    count += 1;
                }
            }
        }
        return count;
    }
};
