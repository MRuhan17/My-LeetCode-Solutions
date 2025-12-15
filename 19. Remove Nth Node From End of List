class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummyNode = new ListNode(0, head);
      
        ListNode fastPointer = dummyNode;
        ListNode slowPointer = dummyNode;
      
        while (n > 0) {
            fastPointer = fastPointer.next;
            n--;
        }
      
        while (fastPointer.next != null) {
            slowPointer = slowPointer.next;
            fastPointer = fastPointer.next;
        }
      
        slowPointer.next = slowPointer.next.next;
      
        return dummyNode.next;
    }
}
