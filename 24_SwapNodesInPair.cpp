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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
            return head;
        if (head->next == nullptr)
             return head;
        
        ListNode *prev = head,
                 *first = head;
        ListNode *second = head->next;
        
        while(second != nullptr && second->next != nullptr){
            if (prev == head)
                swapHeadPair(&head, second);
            else{
                swapNodes(prev, first, second);
            }
            
            prev = first;
            first = first->next;
            second = second->next->next->next;
        }
        
        if (second != nullptr)
            if (prev == head)
                swapHeadPair(&head, second);
            else
                swapNodes(prev, first, second);
        
        return head;
        
    }
    
    void swapNodes(ListNode* prev, ListNode* first, ListNode* second){
        prev->next = second;
        first->next = second->next;
        second->next = first;
    }
    
    void swapHeadPair(ListNode **head, ListNode* second){
        ListNode* temp = *head;
        *head = second;  // Change the head node      
        temp->next = second->next;
        second->next = temp;  
    }
};