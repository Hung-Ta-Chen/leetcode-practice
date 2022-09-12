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
    ListNode* swapNodes(ListNode* head, int k) {  // 1-pass
        ListNode *walkPtr = head, *ptr1, *ptr2;
        
        // First find the kth node
        for(int i = 1; i < k; i++){
            walkPtr = walkPtr->next;
        }
        ptr1 = walkPtr;
        
        // Now find the kth node from the end
        ptr2 = head;
        while(walkPtr->next != nullptr){
            walkPtr = walkPtr->next;
            ptr2 = ptr2->next;
        }
        
        // Swap the value
        int temp = ptr1->val;
        ptr1->val = ptr2->val;
        ptr2->val = temp;
        
        return head;        
    }
};