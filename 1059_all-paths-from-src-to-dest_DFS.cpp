/*
All path from source lead to given destination "dest"
1. No loop in the path (because we can get stuck in the loop forever)
2. No path leads to the destination other than "dest"
3. "dest" having no outgoing edges
*/
class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        vector<bool> is_ancest(n, false);
        
        // Construct adjacency list
        vector<vector<int>> adj_list(n, vector<int>());
        for(int i = 0; i < edges.size(); i++){
            adj_list[edges[i][0]].push_back(edges[i][1]);     
        }
        
        return isToDest(visited, is_ancest, adj_list, source, destination);   
    }
    
    bool isToDest(vector<bool>& visited, vector<bool>& is_ancest, vector<vector<int>>& adj_list, int node, int dest){
        visited[node] = true;
        is_ancest[node] = true;
        
        // Check if the node is a leaf
        if(adj_list[node].size() == 0){
            if(node == dest){
                // The leaf is "dest"
                is_ancest[node] = false;
                return true;
            }
            else{
                // The leaf is not "dest",
                // so the path doesn't lead to dest
                return false;
            }
        }
        else{
            if(node == dest){
                // "dest" is not a destination
                return false;
            }
            else{
                for(int i = 0; i < adj_list[node].size(); i++){
                    if(!visited[adj_list[node][i]]){
                        if(!isToDest(visited, is_ancest, adj_list, adj_list[node][i], dest))
                            return false;
                    }
                    else if(is_ancest[adj_list[node][i]]){
                        // Loop detected
                        return false;  
                    }
                }
            }
        }
        is_ancest[node] = false;
        return true;
    }  
};
