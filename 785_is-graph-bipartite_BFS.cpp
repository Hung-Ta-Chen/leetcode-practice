class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // the color of the nodes (-1: unvisited, 0: color1, 1:color2)
        vector<int> colored(graph.size(), -1);
        
        // Check every node because the graph can be disconnected
        for(int i = 0; i < graph.size(); i++){
            if(colored[i] == -1){
                if(!bipartite_comp(graph,colored, i))
                    return false;
            }
        }
        return true;
    }
    
    bool bipartite_comp(vector<vector<int>>& graph, vector<int>& colored, int src){
        queue<int> q;
        int node;
        
        colored[src] = 0;
        q.push(src);
        
        while(!q.empty()){
            node = q.front();
            q.pop();
            
            for(int i = 0; i < graph[node].size(); i++){
                if(colored[graph[node][i]] == -1){
                    // If the neighbor is uncolored
                    // color it with another color and push it into the queue
                    colored[graph[node][i]] = 1 - colored[node];
                    q.push(graph[node][i]);
                }
                else if(colored[graph[node][i]] == colored[node])
                    // If the color of the neighbor is the same
                    // the graph is not bipartite
                    return false;
            }
        }
        
        return true;
    }
};
