/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        // Record the address of already created nodes
        map<int, Node*> created_nodes;  
        Node* clone = new Node;
        DFS(node, clone, created_nodes);
        
        return clone;
    }
    
    void DFS(Node* node, Node* clone, map<int, Node*>& created_nodes){
        clone->val = node->val;   // Copy the value into the clone node
        clone->neighbors = vector<Node*>();
        created_nodes[clone->val] = clone;  // Save the address of the clone node
        
        for(int i = 0; i < node->neighbors.size(); i++){
            // If the neighbor is already cloned, just push the clone into the neighbor lists
            if(created_nodes.find(node->neighbors[i]->val) != created_nodes.end()){
                clone->neighbors.push_back(created_nodes[node->neighbors[i]->val]);
            }
            // If not
            // Clone the neighbor and do recursively do dfs on it
            // Then push it into the neighbor list
            else{
                Node* clone_neighbor = new Node;
                DFS(node->neighbors[i], clone_neighbor, created_nodes);
                clone->neighbors.push_back(clone_neighbor);
            }
        }
    }
};
