/*
To use a stack for DFS, we have to divide the nodes in the stack into two groups.
One group is the ancestors of the current node, while the other group is those aren't ancestor.
We use a flag to distinguish these two.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses, vector<int>());
        vector<int> visited(numCourses, false);
        vector<int> is_ancest(numCourses, false);

        for(int i = 0; i < prerequisites.size(); i++){
            adj_list[prerequisites[i][0]].push_back(prerequisites[i][1]);   
        }
        
        // Start from every node and check cycle with DFS
        for(int i = 0; i < adj_list.size(); i++){
            if(!visited[i]){
                if(isCyclic(i, adj_list, visited, is_ancest))
                    return false;
            }
        }
        return true;
    }
    
    bool isCyclic(int v, vector<vector<int>>& adj_list, vector<int>& visited, vector<int>& is_ancest){
        visited[v] = true;
        // The current node is the ancestor of its neighbors, so set in_ancest to true
        is_ancest[v] = true;
        
        for(int i = 0; i < adj_list[v].size(); i++){
            if(!visited[adj_list[v][i]]){
                // Recusively check its unvisited neighbors
                if(isCyclic(adj_list[v][i], adj_list, visited, is_ancest)){
                    return true;
                }
            }
            else if(is_ancest[adj_list[v][i]])  // the neighbor is also its ancestor => cycle detected
                return true;
        }
        
        is_ancest[v] = false;
        return false;
    }

};
