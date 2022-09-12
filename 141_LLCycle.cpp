/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Floyd's Algorithm
        if(head == nullptr)
            return false;
        
        if(head->next == nullptr)
            return false;
        
        ListNode *slow = head,
                 *fast = head;
        
        // Slow ptr move forward by 1, fast ptr move forward by 2
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                return true;
        }
        
        return false;
        
    }
};