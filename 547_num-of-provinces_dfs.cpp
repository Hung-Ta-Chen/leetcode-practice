/*
Basically just find the number of connected components
*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<int> visited(n, 0);
        stack<int> s;
        // DFS
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                s.push(i);
                visited[i] = 1;
                while(!s.empty()){
                    int top = s.top();
                    s.pop();
                    for(int j = 0; j < n; j++){
                        if(j != top && isConnected[top][j] == 1 && visited[j] == 0){
                            s.push(j);
                            visited[j] = 1;
                        }
                    }
                }
                count += 1;
            }
        }
        return count;
    }
};
