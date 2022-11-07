class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // shortest distance from source
        vector<int> dist(n, INT_MAX);  
        // In the shortest path or not
        vector<bool> in_path(n, false);
        
        // Construct adjacency list
        vector<vector<pair<int, int>>> adj_list(n, vector<pair<int, int>>());
        for(int i = 0; i < times.size(); i++){
            adj_list[times[i][0]-1].push_back(pair<int, int>(times[i][1], times[i][2]));
        }
        
        // Declare a pq (1st: vertex, 2nd: weight of edge)
        auto comp = [](pair<int, int>& v1, pair<int, int>& v2){
            return v1.second > v2.second;
        };        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        
        // Set the shortest distance of the source as 0
        // then push it into the priority queue
        dist[k-1] = 0;
        pq.push(pair<int, int>(k, dist[k-1]));
        
        while(!pq.empty()){
            // Pop the vertex with the shortest distance
            int min = pq.top().first, min_dist = pq.top().second;
            pq.pop();
            
            // Skip the vertex which is already in the shortest path
            if(in_path[min-1])
                continue;
            
            in_path[min-1] = true;
            
            // See if any neighbor's shortest distance need tp be updated
            for(int i = 0; i < adj_list[min-1].size(); i++){
                if(!in_path[adj_list[min-1][i].first-1] && dist[adj_list[min-1][i].first-1] > min_dist + adj_list[min-1][i].second){
                    dist[adj_list[min-1][i].first-1] = min_dist + adj_list[min-1][i].second;
                    pq.push(pair<int, int>(adj_list[min-1][i].first, dist[adj_list[min-1][i].first-1]));
                }
            }
        }
        
        // Check if there's still infinity distance (disconnected)
        // and find the max shortest distance
        int total_min_dist = INT_MIN;
        for(int i = 0; i < n; i++){
            if(dist[i] == INT_MAX)
                return -1;
            
            if(dist[i] > total_min_dist)
                total_min_dist = dist[i];
        }
        
        return total_min_dist;
    }
};
