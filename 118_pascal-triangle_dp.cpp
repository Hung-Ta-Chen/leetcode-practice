class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pas(numRows, vector<int>());
        pas[0].push_back(1);
        for(int i = 1; i < numRows; i++){
            for(int j = 0; j <= pas[i-1].size(); j++){
                if(j == 0 || j == pas[i-1].size()) pas[i].push_back(1);
                else pas[i].push_back(pas[i-1][j] + pas[i-1][j-1]);
            }
        }
        return pas;
    }
};
