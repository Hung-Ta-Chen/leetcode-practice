class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> table;
        
        // Check row
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                else{
                    if(table.find(board[i][j]) != table.end()) 
                        return false;
                    else 
                        table.insert(board[i][j]);
                }
            }
            table.clear();
        }
        // Check column
        for(int j = 0; j < 9; j++){
            for(int i = 0; i < 9; i++){
                if(board[i][j] == '.') continue;
                else{
                    if(table.find(board[i][j]) != table.end()) 
                        return false;
                    else 
                        table.insert(board[i][j]);
                }
            }
            table.clear();
        }
        // Check grid
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    for(int m = 0; m < 3; m++){
                        if(board[3*i+k][3*j+m] == '.') continue;
                        else{
                            if(table.find(board[3*i+k][3*j+m]) != table.end()){
                                return false;
                            }        
                            else 
                                table.insert(board[3*i+k][3*j+m]);
                        }
                    }
                }
                table.clear();
            }
        }
        return true;
    }
};
