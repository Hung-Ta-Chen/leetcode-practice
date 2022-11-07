class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Shortest distance from source
        // Set the shortest dist to source as 0
        vector<int> dist(n, INT_MAX);  
        dist[k-1] = 0;
        
        // n vertices => at most relaxing edges for n-1 iterations
        for(int i = 0; i < n-1; i++){
            int count = 0;
            // Check every edge
            // If the the original distance is larger than the new one,
            // relax it
            for(int j = 0; j < times.size(); j++){
                int u = times[j][0];
                int v = times[j][1];
                int w = times[j][2];
                
                if(dist[u-1] != INT_MAX && dist[v-1] > dist[u-1] + w){
                    dist[v-1] = dist[u-1] + w;
                    count++;
                }
            }
            
            // Check if there's any update in this iteration,
            // if no, we can stop earlier
            if(count == 0)
                break;
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
