# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # In => head: head of the linked list to be reversed
        # In => k: length of the linked list to be reversed
        # Out => the head and the tail of the reversed linked list
        def reverse_linked_list(head, k):
            if k == 1:
                return (head, head)

            front_node, rev_node = head, head.next
            next_rev_node = rev_node.next
            front_node.next = None

            for i in range(k-1):
                rev_node.next = front_node
                front_node = rev_node
              
                if next_rev_node != None:
                    rev_node = next_rev_node
                    next_rev_node = next_rev_node.next

            return (rev_node, head)

        
        group_head = head
        prev_group_tail = None
        next_group_head = None

        while group_head != None:
            # Locate the tail of the group
            group_tail = group_head
            for i in range(k-1):
                group_tail = group_tail.next
                if group_tail == None:
                    # If the rest of the nodes cannot form a group
                    # don't reverse it
                    prev_group_tail.next = group_head
                    return head 
            
            next_group_head = group_tail.next

            # Isolate the group to be reversed
            group_tail.next = None
            # Reverse the group
            rev_group_head, rev_group_tail = reverse_linked_list(group_head, k)
            # Attach the reversed group to the result
            if prev_group_tail != None:
                prev_group_tail.next = rev_group_head
            else:
                head = rev_group_head
            
            group_head = next_group_head
            prev_group_tail = rev_group_tail
        
        return head
