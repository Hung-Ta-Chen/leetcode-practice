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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        //prev: last reversed node
        //curr: the node to be reversed
        //next: next node to be reversed
        ListNode *prev = nullptr, *curr = head, *next = head->next;
        
        while(next != nullptr){
            prev = curr;
            curr = next;
            next = next->next;
            curr->next = prev;
        }
        
        head->next = nullptr;  //1st node still connected to 2nd node, so we cut it off
        head = curr;           //Change the head since the list is reversed
        return head;
    }
};
