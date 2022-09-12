/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Empty list
        if(head == nullptr) return nullptr;
        
        set<int>exist_set;
        set<int>::iterator iter;
        
        ListNode* walk_ptr = head;
        ListNode* prev_ptr = nullptr;
        ListNode* temp_ptr = nullptr;
        
        // First node
        exist_set.insert(walk_ptr->val);
        prev_ptr = walk_ptr;
        walk_ptr = walk_ptr->next;
        
        // Other nodes
        while(walk_ptr != nullptr){
            iter = exist_set.find(walk_ptr->val);
            if(iter == exist_set.end()){
                // Register new element into the set
                exist_set.insert(walk_ptr->val);
                
                prev_ptr = walk_ptr;
                walk_ptr = walk_ptr->next;
            }
            else{
                // Delete duplicates
                prev_ptr->next = walk_ptr->next;
                temp_ptr = walk_ptr;
                walk_ptr = walk_ptr->next;
                
                delete temp_ptr;
            }
        }       
        return head;
    }
};