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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
            return nullptr;
        
        if(head->next == nullptr)
            return nullptr;
        
        ListNode *slow = head,
                 *fast = head;
     
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                return findCycleStart(head, fast);
        }        
        return nullptr;
    }
    
    ListNode *findCycleStart(ListNode *head, ListNode *meetNode){
        // One ptr start from head, one ptr start from the encountering node
        // Both move forward by one, then they'll meet at the start of cycle
        ListNode* walk = head;
        
        while(walk != meetNode){
            walk = walk->next;
            meetNode = meetNode->next;
        }
        
        return walk;
    }
};