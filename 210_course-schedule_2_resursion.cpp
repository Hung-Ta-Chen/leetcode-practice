class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses, vector<int>());
        vector<int> visited(numCourses, false);
        vector<int> is_ancest(numCourses, false);
        vector<int> in_topo(numCourses, false);
        vector<int> topo_order;

        for(int i = 0; i < prerequisites.size(); i++){
            adj_list[prerequisites[i][0]].push_back(prerequisites[i][1]);   
        }
        
        // Start from every node and do DFS
        for(int i = 0; i < adj_list.size(); i++){
            if(!visited[i]){
                if(isCyclic(i, adj_list, visited, is_ancest, in_topo, topo_order))
                    return vector<int>();   // If the graph is cyclic, return empty list
            }
        }
        return topo_order;
    }
    
    bool isCyclic(int v, vector<vector<int>>& adj_list, vector<int>& visited, vector<int>& is_ancest, vector<int>& in_topo, vector<int>& topo){
        visited[v] = true;
        // The current node is the ancestor of its neighbors, so set in_ancest to true
        is_ancest[v] = true;
        
        for(int i = 0; i < adj_list[v].size(); i++){
            if(!visited[adj_list[v][i]]){
                // Recusively check its unvisited neighbors
                if(isCyclic(adj_list[v][i], adj_list, visited, is_ancest, in_topo, topo)){
                    return true;
                }
            }
            else if(is_ancest[adj_list[v][i]])  // the neighbor is also its ancestor => cycle detected
                return true;
        }
        
        // After all neighbors of the current node is traversed
        // Push it into the topo order
        is_ancest[v] = false;
        if(!in_topo[v]){
            topo.push_back(v);
            in_topo[v] = true;
        }
        return false;
    }
};
