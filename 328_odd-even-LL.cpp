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
    ListNode* oddEvenList(ListNode* head) {
        // Special cases
        if(head == nullptr) return head;
        if(head->next == nullptr) return head;
        if(head->next->next == nullptr) return head;
        
        // General cases
        ListNode* even = head->next;
        ListNode* prev = head;
        ListNode* tail = head;
        // Find the tail of LL
        while(tail->next != nullptr){ 
            tail = tail->next;
        }
        ListNode* o_tail = tail;   // Remember the original tail
        
        while(prev != o_tail){
            // Move the even node to the tail
            prev->next = even->next;
            even->next = nullptr;
            tail->next = even;
            
            //Update part
            // If the orignial tail is moved, leave the loop (even length)
            if(even == o_tail) break;    
            else{
                prev = prev->next;
                even = prev->next;
                tail = tail->next;
            }
        }
        
        return head;     
    }
};
