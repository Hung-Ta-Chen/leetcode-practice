/*
We start from the bottom of the grids.  (. indicates wall, c indicates current position [i, j])
case 1:  at the left wall => ball get stuck at the wall => -1
.|c|  <- current row
.|/|  <- next row

case 2:  at the right wall => ball get stuck at the wall => -1
|c|.  <- current row
|\|.  <- next row

case 3: the pos that ball will fall = the pos that ball will fall from [i+1, j+1]
|c| |  <- current row
|\|\|  <- next row

case 4: the pos that ball will fall = the pos that ball will fall from [i+1, j-1]
| |c|  <- current row
|/|/|  <- next row

case 5, 6: ball get stuck => -1
| |c|  <- current row
|\|/|  <- next row

|c| |  <- current row
|\|/|  <- next row
*/
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n, -1));
        for(int j = 0; j < n; j++){
            dp[m][j] = j;
        }
        // bottom-up
        for(int i = m - 1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(j == 0 && grid[i][j] == -1) dp[i][j] = -1;
                else if(j == n-1 && grid[i][j] == 1) dp[i][j] = -1;
                else if(grid[i][j] == 1 && grid[i][j+1] == 1) dp[i][j] = dp[i+1][j+1];
                else if(grid[i][j] == -1 && grid[i][j-1] == -1) dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = -1;
            }
        }
        return dp[0];
    }
};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
