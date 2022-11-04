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
        
        // To mark whether the node is the ancestor of current node in DFS
        vector<int> is_ancest(numCourses, false);  
        stack<int> s;
        
        for(int i = 0; i < prerequisites.size(); i++){
            adj_list[prerequisites[i][0]].push_back(prerequisites[i][1]);   
        }
        
        for(int i = 0; i < adj_list.size(); i++){
            if(!visited[i]){
                s.push(i);
                
                while(!s.empty()){
                    int top = s.top();
                    // Set the current node as visited
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
                            return false;   // Its neighbor is also its ancestor => cycle detected
                        }
                    }

                    // If no neighbor pushed into the stack, it's a dead-end
                    // pop it and change the ancestor flag to false (it's an ancestor of no one)
                    if(top == s.top()){
                        s.pop();
                        is_ancest[top] = false;
                    }

                }   
            }
        }       
        return true;
    }
};
