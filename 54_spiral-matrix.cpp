class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> order;
        int m = matrix.size(), n = matrix[0].size();
        int j_direct = 1, i_direct = 1;
        int j_step = n, i_step = m-1;
        // flag: to change i or j,  count: # of traversed elements
        int flag = 0, count = 0;
        // Let the index start from [0][-1] (left side of the 1st element)
        int j = -1, i = 0;     
        while(count < m*n){
            if(flag % 2 == 0){
                for(int k = 0; k < j_step; k++){
                    j += j_direct;
                    order.push_back(matrix[i][j]); 
                    count++;
                }
                j_step--;
                j_direct *= (-1);  // Change direction of j
            }
            else{
                for(int k = 0; k < i_step; k++){
                    i += i_direct;
                    order.push_back(matrix[i][j]);
                    count++;
                }
                i_step--;
                i_direct *= (-1);  // Change direction of i
            }
            flag++;
        }
        return order;
    }
};
