class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //vector<int> visited(graph.size(), false);  // Not used in this problem
        vector<int> is_ancest(graph.size(), false);
        vector<int> path;
        vector<vector<int>> all_paths;
        
        find_path(graph, is_ancest, path, all_paths, 0, graph.size()-1);
        return all_paths;
    }
    
    void find_path(vector<vector<int>>& graph, vector<int>& is_ancest, vector<int>& path, vector<vector<int>>& all_paths, int node, int target){
        // Mark the node as ancestor
        // since it will be the ancestor of the its neighbors
        is_ancest[node] = true;  
        // Include the current node into the path
        path.push_back(node);
        
        // If target is reached, push the path into all_paths
        if(node == target)
            all_paths.push_back(path);
        else{
            // Recursively do DFS
            for(int i = 0; i < graph[node].size(); i++){
                if(!is_ancest[graph[node][i]]){
                    find_path(graph, is_ancest, path, all_paths, graph[node][i], target);
                }
            }
        }
        
        // No more depth to traverse
        // backtrack
        is_ancest[node] = false;
        path.pop_back();        
    }
};
