class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //Flip the matrix upside down first
        for(int j = 0; j < n; j++){
            for(int i = 0; i <= (n-1)/2; i++){
                swap(matrix[i][j], matrix[n-1-i][j]);
            }
        }
        
        //Then flip the matrix by its diagonal
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                if(i != j){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }    
    } 
};