class Solution(object):
    def deleteDuplicates(self, head):
        p = head
        while head:
            while head.next and head.val == head.next.val:
                head.next = head.next.next
            head = head.next
        return p
