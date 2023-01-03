class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool match = false;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                match = match | matching(board, word, 0, i, j);   // Traverse through all grids
            }
        }
        return match;
    }
    // DFS
    bool matching(vector<vector<char>>& board, string& word, int idx, int i, int j){
        int m = board.size(), n = board[0].size();
        if(idx == word.size()) return true;   // index of atring out of range => all chars matched
        if(i < 0 || i > m-1 || j < 0 || j > n-1 || board[i][j] != word[idx]) return false; 
        bool match = false;
        board[i][j] = '_';   // Change the current character to avoid repeat
        int i_move[4] = {1, 0, -1, 0};
        int j_move[4] = {0, 1, 0, -1};
        for(int k = 0; k < 4; k++){
            match = match | matching(board, word, idx+1, i+i_move[k], j+j_move[k]);
            if(match) break;
        }
        board[i][j] = word[idx];   // Change the current character back
        return match;
    }
};
