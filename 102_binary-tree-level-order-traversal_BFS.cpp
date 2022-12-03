/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> order;
        if(root == nullptr) return order; 
        
        queue<pair<TreeNode*, int>> bfs;
        vector<int> same_lvl;    
        bfs.push(pair<TreeNode*, int>(root, 1));
        int current_lvl = 1;
        while(!bfs.empty()){
            pair<TreeNode*, int> front = bfs.front();
            bfs.pop();
            // Check level
            if(front.second == current_lvl)
                // the front node is still at the same level
                same_lvl.push_back(front.first->val);
            else{
                // the front node is at a new level
                // push the previous level into answer
                order.push_back(same_lvl);
                same_lvl.clear();
                same_lvl.push_back(front.first->val);
                current_lvl++;
            }
            // Push left child into the queue
            if(front.first->left != nullptr)
                bfs.push(pair<TreeNode*, int>(front.first->left, front.second+1));
            // Push right child into the queue
            if(front.first->right != nullptr)
                bfs.push(pair<TreeNode*, int>(front.first->right, front.second+1));
        }
        // Push the vector of last level into answer
        order.push_back(same_lvl);
        return order;
    }
};
