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
// ~~~~~~~~~~~~~
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p != nullptr && q == nullptr) return false;
        if(p == nullptr && q != nullptr) return false;
        
        // Use stacks to implement dfs on both trees
        stack<TreeNode*> stack1;
        stack<TreeNode*> stack2;
        
        stack1.push(p);
        stack2.push(q);
        
        // Compare every node in dfs, including nullptr
        while(!stack1.empty() && !stack2.empty()){
            TreeNode* node1 = stack1.top();
            TreeNode* node2 = stack2.top();
            stack1.pop();
            stack2.pop();
            
            if(node1 == nullptr && node2 == nullptr) continue;
            if(node1 != nullptr && node2 == nullptr) return false;
            if(node1 == nullptr && node2 != nullptr) return false;
            if(node1->val != node2->val) return false;
            
            stack1.push(node1->left);
            stack1.push(node1->right);
            stack2.push(node2->left);
            stack2.push(node2->right);    
        }
        
        if(stack1.empty() && !stack2.empty()) return false;
        if(!stack1.empty() && stack2.empty()) return false;
        return true;        
    }
};
