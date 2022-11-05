// To see if a graph is a tree
// 1. check if the graph has cycle
// 2. check if the graph is connected
//
// For cycle checking part,
// since the parent node is also a neighbor in the nondirected graph
// we have to remember the parent node
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<bool> is_ancest(n, false);
        // Construct adjacency list
        vector<vector<int>> adj_list(n, vector<int>());
        for(int i = 0; i < edges.size(); i++){
            adj_list[edges[i][0]].push_back(edges[i][1]);     
            adj_list[edges[i][1]].push_back(edges[i][0]);     
        }
        
        // Since we only want connected graph
        // We don't need to do DFS from every node
        /* 
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(isCycle(visited, is_ancest, adj_list, i, -1)){
                    return false;
                }
            }
        }*/
        
        if(isCycle(visited, is_ancest, adj_list, 0, -1)){
            // Return false if there's cycle in the graph
            return false;
        }
        else{
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum += visited[i];
            }            
            return sum == n;
        }
    }
    
    bool isCycle(vector<bool>& visited, vector<bool>& is_ancest, vector<vector<int>>& adj_list, int node, int parent){
        visited[node] = true;
        is_ancest[node] = true;
        
        for(int i = 0; i < adj_list[node].size(); i++){
            if(!visited[adj_list[node][i]]){
                if(isCycle(visited, is_ancest, adj_list, adj_list[node][i], node)){
                    return true;
                }
            }
            else if(is_ancest[adj_list[node][i]] && adj_list[node][i] != parent)
                // If the neighbor is a non-parent ancestor
                return true;  
        }
        
        is_ancest[node] = false;
        return false;
    }
};
