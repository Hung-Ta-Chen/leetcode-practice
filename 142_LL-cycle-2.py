# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        fast = head
        while fast and fast.next:          
            slow = slow.next
            if (fast := fast.next.next) == slow: 
                temp = head
                while temp != slow:
                    temp = temp.next
                    slow = slow.next
                return temp    
        return None
