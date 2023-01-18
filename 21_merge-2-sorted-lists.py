# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        merged = ListNode()
        walk = merged
        while list1 and list2:
            if list1.val < list2.val:
                walk.next = list1
                list1 = list1.next
            else:
                walk.next = list2
                list2 = list2.next
            walk = walk.next
        if list1:
            walk.next = list1
        if list2:
            walk.next = list2
        return merged.next
