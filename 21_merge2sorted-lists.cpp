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
        ListNode* listPtr1 = list1;
        ListNode* listPtr2 = list2;
        ListNode head = ListNode();   // dummy node
        ListNode* walkPtr = &head;
        
        while(listPtr1 != nullptr && listPtr2 != nullptr){
            if (listPtr1->val < listPtr2->val){
                walkPtr->next = listPtr1;    // set node l1Ptr points to as the next node
                listPtr1 = listPtr1->next;   // move l1Ptr to next node
            }
            else{
                walkPtr->next = listPtr2;    // set node l2Ptr points to as the next node
                listPtr2 = listPtr2->next;   // move l2Ptr to next node
            }
            walkPtr = walkPtr->next;         // move walkPtr to the next node
            walkPtr->next = nullptr;
        }
        
        while(listPtr1 != nullptr){
            walkPtr->next = listPtr1;
            listPtr1 = listPtr1->next;
            walkPtr = walkPtr->next;
            walkPtr->next = nullptr;
        }
        
        while(listPtr2 != nullptr){
            walkPtr->next = listPtr2;
            listPtr2 = listPtr2->next;
            walkPtr = walkPtr->next;
            walkPtr->next = nullptr;
        }
        
        return head.next;
    } 
};