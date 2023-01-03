class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        // Put all boundary grids in the array
        vector<pair<int, int>> boundary;
        for(int i = 0; i < m; i++){
            boundary.push_back(make_pair(i, 0));
            boundary.push_back(make_pair(i, n-1));
        } 
        for(int j = 0; j < n; j++){
            boundary.push_back(make_pair(0, j));
            boundary.push_back(make_pair(m-1, j));
        } 
        stack<pair<int, int>> s;
        for(int k = 0; k < boundary.size(); k++){
            int i = boundary[k].first, j = boundary[k].second;
            // If 'O' is found on the boundary, do DFS from it
            // and change every 'O' found to 'N' 
            if(board[i][j] == 'O'){
                s.push(make_pair(i, j));
                board[i][j] = 'N';
                while(!s.empty()){
                    int curr_i = s.top().first, curr_j = s.top().second;
                    s.pop();
                    if(curr_i != 0 && board[curr_i-1][curr_j] == 'O'){
                        s.push(make_pair(curr_i-1, curr_j));
                        board[curr_i-1][curr_j] = 'N';
                    }
                    if(curr_i != m-1 && board[curr_i+1][curr_j] == 'O'){
                        s.push(make_pair(curr_i+1, curr_j));
                        board[curr_i+1][curr_j] = 'N';
                    }
                    if(curr_j != 0 && board[curr_i][curr_j-1] == 'O'){
                        s.push(make_pair(curr_i, curr_j-1));
                        board[curr_i][curr_j-1] = 'N';
                    }
                    if(curr_j != n-1 && board[curr_i][curr_j+1] == 'O'){
                        s.push(make_pair(curr_i, curr_j+1));
                        board[curr_i][curr_j+1] = 'N';
                    }
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'N') board[i][j] = 'O';
            }
        }
    }  
};
