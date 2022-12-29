/*
Really interesting fact
You can always maintain the size of the queue as the size of following level at the start of an iteration,
if you pop all the nodes in the previous level in the last iteration.
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int lvl_size = q.size();
            for(int i = 0; i < lvl_size; i++){
                Node* n = q.front();
                q.pop();
                n->next = (i == lvl_size-1)?nullptr:q.front();
                if(n->left != nullptr) q.push(n->left);
                if(n->right != nullptr) q.push(n->right);
            }
        }
        return root;  
    }
};
