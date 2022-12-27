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
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode *dummy = new ListNode(0, head);  // Use a dummy node to avoid checking boundary case
        head = dummy;
        ListNode *curr = dummy->next, *prev = dummy; 
        while(curr->next != nullptr){
            if(curr->val != curr->next->val){
                prev = curr;
                curr = curr->next;
            }
            else{
                while(curr->next != nullptr && curr->val == curr->next->val){
                    curr = curr->next;
                }
                prev->next = curr->next; 
                if(curr->next == nullptr) break;
                else curr = curr->next;
            }
        }
        return dummy->next;
    }
};
