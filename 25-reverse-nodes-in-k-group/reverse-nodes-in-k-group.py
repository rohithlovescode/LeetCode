class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if k == 1:
            return head

        # sets first.next as last.next, and others next immediately preceding
        # sets pre_first.next or head to point to the new first 
        def reverse(first, last, pre_first):
            nonlocal head
            # take care of link to new first node
            if pre_first:
                pre_first.next = last
            else:
                head = last
        
            prev, curr = first, first.next
            first.next = last.next  # take care of link to remaining nodes
            for _ in range(k-1):
                curr.next, prev, curr = prev, curr, curr.next

        count = 1
        curr = first = head
        pre_first = None
        while curr:
            if count == k:
                # we have reached the kth node, now it's time to reverse and reset
                reverse(first, curr, pre_first)
                pre_first = first
                curr, first = first.next, first.next
                count = 1
            else:
                curr = curr.next
                count += 1
        
        return head
        