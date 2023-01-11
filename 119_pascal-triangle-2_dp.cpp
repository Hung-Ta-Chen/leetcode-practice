class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pas(rowIndex+1, vector<int>(rowIndex+1, 0));
        pas[0][0] = 1;
        for(int i = 1; i <= rowIndex; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i) pas[i][j] = 1;
                else pas[i][j] = pas[i-1][j-1] + pas[i-1][j];
            }
        }
        return pas[rowIndex];
    }
};
