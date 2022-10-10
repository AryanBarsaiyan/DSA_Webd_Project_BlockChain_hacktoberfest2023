class Solution {
    public int getSize(ListNode head){
        int count = 0;
        while(head != null){
            count++;
            head = head.next;
        }
        return count;
    }
    public ListNode reverseKGroup_(ListNode head, int k, int size) {
        if(head == null || head.next == null || size < k)
            return head;
        ListNode prev = null, curr = null, forward = null;
        curr = head;
        int currPos = k;
        while(curr != null &&  currPos > 0){
            forward = curr.next;
            curr.next = prev;
            prev = curr;
            curr = forward;
            currPos--;
        }
        size -= k;
        if(forward != null)
          head.next = reverseKGroup_(forward, k, size);
        return prev;
    }
    public ListNode reverseKGroup(ListNode head, int k){
        int size = getSize(head);
        return reverseKGroup_(head, k, size);
    }
}
