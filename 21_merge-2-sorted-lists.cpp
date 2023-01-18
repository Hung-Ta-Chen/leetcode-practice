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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;       
        // Directly reuse the nodes in list1 & list2 to save memory
        ListNode head = ListNode();   // dummy node
        ListNode* walkPtr = &head;        
        while(list1 != nullptr && list2 != nullptr){
            if (list1->val < list2->val){
                walkPtr->next = list1;    // set node l1Ptr points to as the next node
                list1 = list1->next;   // move l1Ptr to next node
            }
            else{
                walkPtr->next = list2;    // set node l2Ptr points to as the next node
                list2 = list2->next;   // move l2Ptr to next node
            }
            walkPtr = walkPtr->next;         // move walkPtr to the next node
        }        
        if(list1 != nullptr) walkPtr->next = list1; 
        if(list2 != nullptr) walkPtr->next = list2;
        return head.next;
    } 
};
