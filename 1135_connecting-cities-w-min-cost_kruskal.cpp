class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<int> parent(n, -1);
        vector<int> rank(n, 1);
        //vector<vector<int>> MST;
        for(int i = 0; i < n; i++) {
            parent[i] = i+1;
        }
        
        // Sort the connections
        sort(connections.begin(), connections.end(), [](vector<int>& v1, vector<int>& v2){
            return v1[2] < v2[2];
        });
        
        int cost = 0;
        for(int i = 0; i < connections.size(); i++){
            // If the new edge doesn't form a cycle, include it
            if(find(parent, connections[i][0]) != find(parent, connections[i][1])){
                //MST.push_back(connections[i]);
                cost += connections[i][2];
            }     
            // Add the edge into the union
            union_sets(parent, rank, connections[i][0], connections[i][1]);
        }
        
        int common_parent = find(parent, 1);
        for(int i = 1; i < n; i++){
            if(find(parent, i+1) != common_parent)
                return -1;
        }
        
        return cost;
    }
    
    // Recursive find the parent of the set
    int find(vector<int>& parent, int node){
        if(parent[node-1] == node)
            return node;
        else{
            // Use path compression to move the intermediate nodes aw the child of the parent
            parent[node-1] = find(parent, parent[node-1]);
            return parent[node-1];
        }            
    }
    
    // Union the sets
    // 1. if the rank of two sets is different, include the small one into the large one
    // 2. if the rank is the same, include one to another and increment the rank
    void union_sets(vector<int>& parent, vector<int>& rank, int u, int v){
        int root_u = find(parent, u);
        int root_v = find(parent, v);
        
        if(rank[root_u-1] > rank[root_v-1]){
            parent[root_v-1] = parent[root_u-1];
        }
        else if(rank[root_u-1] < rank[root_v-1]){
            parent[root_u-1] = parent[root_v-1];
        }
        else{
            parent[root_u-1] = parent[root_v-1];
            rank[root_v-1]++;
        }
    }
    
};
