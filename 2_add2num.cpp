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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        int sum = 0;
        ListNode* listNodePtr1 = l1;
        ListNode* listNodePtr2 = l2;
        ListNode head = ListNode();
        ListNode* resultListHead = &head;
        ListNode* tempPtr;
        ListNode* walkPtr = resultListHead;

        // Traverse through two lists and add them digit by digit
        while(listNodePtr1 != nullptr && listNodePtr2 != nullptr){
            sum = listNodePtr1->val + listNodePtr2->val + flag;
            flag = sum / 10;
            sum = sum % 10;


            tempPtr = new ListNode;
            tempPtr->val = sum;
            tempPtr->next = nullptr;
            walkPtr->next = tempPtr;
            walkPtr = walkPtr->next;

            listNodePtr1 = listNodePtr1->next;
            listNodePtr2 = listNodePtr2->next;
        }

        // Concat the remaining digits
        while(listNodePtr2 != nullptr){
            sum = listNodePtr2->val + flag;
            flag = sum / 10;
            sum = sum % 10;

            tempPtr = new ListNode;
            tempPtr->val = sum;
            tempPtr->next = nullptr;

            walkPtr->next = tempPtr;
            walkPtr = walkPtr->next;
            listNodePtr2 = listNodePtr2->next;
        }

        while(listNodePtr1 != nullptr){
            sum = listNodePtr1->val + flag;
            flag = sum / 10;
            sum = sum % 10;


            tempPtr = new ListNode;
            tempPtr->val = sum;
            tempPtr->next = nullptr;
            walkPtr->next = tempPtr;
            walkPtr = walkPtr->next;
            listNodePtr1 = listNodePtr1->next;
        }
    
        // Check the carry
        if (flag == 1){
            tempPtr = new ListNode;
            tempPtr->val = flag;
            tempPtr->next = nullptr;
            walkPtr->next = tempPtr;
            walkPtr = walkPtr->next;
        }

        return resultListHead->next;
    }
};