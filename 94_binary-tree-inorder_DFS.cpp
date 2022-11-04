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
    // inorder: left-root-right
    vector<int> inorderTraversal(TreeNode* root) {
        set<TreeNode*> visited;
        vector<int> inorder;
        if(root == nullptr) return inorder;
        
        stack<TreeNode*> stack;
        stack.push(root);
        
        while(!stack.empty()){
            TreeNode* node = stack.top();
            stack.pop();
            
            if(node->left == nullptr || is_visit(visited, node->left)){
                // Now left child to be visited. so we can read this node now.
                inorder.push_back(node->val);
                visited.insert(node);  // Remember we already visited this node.
                
                // If there's right child, push it to the stack for following visit.
                if(node->right != nullptr){    
                    if(!is_visit(visited, node->right))
                        stack.push(node->right);
                }
            }
            else{
                stack.push(node);
                stack.push(node->left);
            }  
        }
        
        return inorder;
    }
    
    bool is_visit(set<TreeNode*> &visited, TreeNode* node){
        if(visited.find(node) != visited.end())
            return true;
        else
            return false;
    }
};
