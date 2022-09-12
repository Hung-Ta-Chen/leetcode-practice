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
    ListNode* sortList(ListNode* head) {
        // Special case (length = 0 or 1)
        if(head == nullptr || head->next == nullptr)
            return head;
        
        // find the midpoint of the ll
        ListNode *fastPtr = head,
                 *slowPtr = head;
        ListNode *tempPtr = nullptr;
        
        // ***注意這的寫法
        while(fastPtr != nullptr && fastPtr->next != nullptr){
            tempPtr = slowPtr;  // Get the last node of left list
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
        
        // Now divide the linked-list into two lls and sort them recursively
        tempPtr->next = nullptr;  // Divide the list        
        ListNode *leftSortList = sortList(head);
        ListNode *rightSortList = sortList(slowPtr);
        
        // Combine two sorted lists
        ListNode *newHead = merge(leftSortList, rightSortList);
        return newHead;
    }
    
    ListNode* merge(ListNode* leftHead, ListNode* rightHead){
        // In-place version of merge
        // No need to allocate memory for temporary usage,
        // just re-arange the existing memory
        // Therefore this version can save the time of dynamically allocating memory
        ListNode* newHead = new ListNode;
        newHead->val = 0; newHead->next = nullptr;
        ListNode* walkPtr = newHead;
        
        ListNode *leftPtr = leftHead,
                 *rightPtr = rightHead;
        
        while(leftPtr != nullptr && rightPtr != nullptr){
            if(leftPtr->val < rightPtr->val){
                walkPtr->next = leftPtr;
                walkPtr = walkPtr->next;
                leftPtr = leftPtr->next;
                walkPtr->next = nullptr;
            }
            else{
                walkPtr->next = rightPtr;
                walkPtr = walkPtr->next;
                rightPtr = rightPtr->next;
                walkPtr->next = nullptr;
            }
        }
        
        while(leftPtr != nullptr){
            walkPtr->next = leftPtr;
            walkPtr = walkPtr->next;
            leftPtr = leftPtr->next;
            walkPtr->next = nullptr;
        }
        
        while(rightPtr != nullptr){
            walkPtr->next = rightPtr;
            walkPtr = walkPtr->next;
            rightPtr = rightPtr->next;
            walkPtr->next = nullptr;
        }

        return newHead->next;
    }
};