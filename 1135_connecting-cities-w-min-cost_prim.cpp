class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        // Set the cut weight of source as 0, other as INF
        vector<int> cut_weight(n, INT_MAX);
        cut_weight[0] = 0;
        
        vector<bool> in_MST(n, false);
        
        // Comparator for priority queue
        auto comp = [](pair<int, int>& v1, pair<int, int>& v2){
            return v1.second > v2.second;  
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        
        // Construct adjacency list (first: vertex, second: weight of edge)
        vector<vector<pair<int, int>>> adj_list(n, vector<pair<int, int>>());
        for(int i = 0; i < connections.size(); i++){
            adj_list[connections[i][0]-1].push_back(pair<int, int>(connections[i][1], connections[i][2]));
            adj_list[connections[i][1]-1].push_back(pair<int, int>(connections[i][0], connections[i][2]));
        }
        
        // Push the source into the priority queue
        pq.push(pair<int, int>(1, cut_weight[0]));
        
        int cost = 0;
        while(!pq.empty()){
            int min = pq.top().first;
            int weight = pq.top().second;
            
            pq.pop();
            
            // If the min-weight vertex is already in MST, skip it
            if(in_MST[min-1])
                continue;
            
            in_MST[min-1] = true;
            cost += weight;
            
            // Check if the weight of neighbors need update
            // If so, update the weight and push the updated one into the priority queue
            for(int i = 0; i < adj_list[min-1].size(); i++){
                if(!in_MST[adj_list[min-1][i].first-1] && cut_weight[adj_list[min-1][i].first-1] > adj_list[min-1][i].second){
                    cut_weight[adj_list[min-1][i].first-1] = adj_list[min-1][i].second;
                    pq.push(pair<int, int>(adj_list[min-1][i].first, cut_weight[adj_list[min-1][i].first-1]));
                }         
            }
        }
        
        // If the cut weight of any vertex is still INF
        // means that the graph is disconnected
        // return -1
        for(int i = 0; i < n; i++) {
            if(!in_MST[i])
                return -1;
        }
        
        return cost;
    }
};
