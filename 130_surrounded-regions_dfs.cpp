/*
My first thought:
Use DFS to traverse through all the 'O' regions.
If it ends up to be surrounded, capture it.
If not, do nothing.
This is quite inefficient.

Improvement:
The other way to do it is to check all the boundary O.
And without using a "visited" 2D array, we modify the array in-place to reduce memory used.
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        stack<pair<int, int>> s;
        set<pair<int, int>> set;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    set.clear();
                    // DFS
                    bool is_surrounded = true;
                    s.push(make_pair(i, j));
                    visited[i][j] = true;
                    while(!s.empty()){
                        int curr_i = s.top().first, curr_j = s.top().second;
                        s.pop();
                        set.insert(make_pair(curr_i, curr_j));
                        if(curr_i == 0 || curr_i == m-1 || curr_j == 0 || curr_j == n-1) is_surrounded = false;
                        if(curr_i != 0 && board[curr_i-1][curr_j] == 'O' && visited[curr_i-1][curr_j] != 1){
                            s.push(make_pair(curr_i-1, curr_j));
                            visited[curr_i-1][curr_j] = 1;
                        }
                        if(curr_i != m-1 && board[curr_i+1][curr_j] == 'O' && visited[curr_i+1][curr_j] != 1){
                            s.push(make_pair(curr_i+1, curr_j));
                            visited[curr_i+1][curr_j] = 1;
                        }
                        if(curr_j != 0 && board[curr_i][curr_j-1] == 'O' && visited[curr_i][curr_j-1] != 1){
                            s.push(make_pair(curr_i, curr_j-1));
                            visited[curr_i][curr_j-1] = 1;
                        }
                        if(curr_j != n-1 && board[curr_i][curr_j+1] == 'O' && visited[curr_i][curr_j+1] != 1){
                            s.push(make_pair(curr_i, curr_j+1));
                            visited[curr_i][curr_j+1] = 1;
                        }
                    }
                    if(is_surrounded){
                        for(auto iter = set.begin(); iter != set.end(); iter++){
                            int cap_i = iter->first, cap_j = iter->second;
                            board[cap_i][cap_j-1] = 'X';
                        }
                    }
                }
            }
        }
    }  
};
