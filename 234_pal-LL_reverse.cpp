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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        
        // Push the elements in first half into the stack
        ListNode *slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr){
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // If the length of LL is odd, ignore the middle point
        if(fast != nullptr) slow = slow->next;  
        
        // Now compare elements in stack with the elements in second half of the LL
        while(slow != nullptr){
            if(slow->val != s.top()) return false;
            else{
                s.pop();
                slow = slow->next;
            }
        }
        
        return true;
    }
};
