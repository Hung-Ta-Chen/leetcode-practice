class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses, vector<int>());
        vector<int> visited(numCourses, false);
        vector<int> in_topo(numCourses, false);  // Check if a node is already in the topo
        
        // To mark whether the node is the ancestor of current node in DFS
        vector<int> is_ancest(numCourses, false);  
        stack<int> s;
        queue<int> topo_q;
        
        for(int i = 0; i < prerequisites.size(); i++){
            adj_list[prerequisites[i][0]].push_back(prerequisites[i][1]);   
        }
        
        for(int i = 0; i < adj_list.size(); i++){
            if(!visited[i]){
                s.push(i);
                
                while(!s.empty()){
                    int top = s.top();
                    visited[top] = true;
                    
                    // Current node will be the ancestor of its neighbors,
                    // so change the ancestor flag to true
                    is_ancest[top] = true;   

                    for(int j = 0; j < adj_list[top].size(); j++){
                        if(!visited[adj_list[top][j]]){
                            // Push the unvisited neighbors in stack and marked them as visited
                            s.push(adj_list[top][j]);
                        }
                        else if(is_ancest[adj_list[top][j]]){
                            // Its neighbor is also its ancestor
                            // cycle detected
                            // return empty list
                            return vector<int>();   
                        }
                    }

                    // If no neighbor pushed into the stack, it's a dead-end
                    // pop it and change the ancestor flag to false
                    if(top == s.top()){
                        s.pop();
                        is_ancest[top] = false;
                        // Push the popped node into topo queue
                        // Since there might be duplicated nodes in the stack
                        // we ignore the duplicate when one node is already in topo order
                        if(!in_topo[top]){
                            topo_q.push(top);
                            in_topo[top] = true;
                        }                        
                    }

                }   
            }
        } 
        
        // Push the nodes in the queue into the list
        vector<int> topo_order;
        while(!topo_q.empty()){
            topo_order.push_back(topo_q.front());
            topo_q.pop();
        }
        return topo_order;
    }
};
