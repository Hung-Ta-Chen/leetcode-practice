// Definition for a Node.
/*
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));  // Record the level of the node
        while(!q.empty()){
            Node* n = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(n->left != nullptr) q.push(make_pair(n->left, lvl+1));
            if(n->right != nullptr) q.push(make_pair(n->right, lvl+1));
            if(q.empty() || q.front().second != lvl) n->next = nullptr;
            else n->next = q.front().first;
        }
        return root;  
    }
};
