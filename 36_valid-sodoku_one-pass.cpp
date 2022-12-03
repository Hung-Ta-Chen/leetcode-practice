class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> flag_r;
        set<char> flag_c;
        set<char> flag_g;
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(flag_r.find(board[i][j]) != flag_r.end()) return false;
                    else flag_r.insert(board[i][j]);
                }
                if(board[j][i] != '.'){
                    if(flag_c.find(board[j][i]) != flag_c.end()) return false;
                    else flag_c.insert(board[j][i]);
                }
                if(board[j/3+(i%3)*3][(i/3)*3+(j%3)] != '.'){
                    if(flag_g.find(board[j/3+(i%3)*3][(i/3)*3+(j%3)]) != flag_g.end()) return false;
                    else flag_g.insert(board[j/3+(i%3)*3][(i/3)*3+(j%3)]);
                }
            }
            flag_r.clear();
            flag_c.clear();
            flag_g.clear();
        } 
        return true;
    }
};
