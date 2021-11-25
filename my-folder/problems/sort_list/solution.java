/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode merge(ListNode a, ListNode b) {
        if(a == null) return b;
        if(b == null) return a;
        
        ListNode head = new ListNode(0), tail = head;
        while(a != null && b != null && tail != null) {
            if(a.val <= b.val) {
                tail.next = a;
                a = a.next;
            } else {
                tail.next = b;
                b = b.next;
            }
            tail = tail.next;
        }
        
        if(a != null) tail.next = a;
        else if(tail != null) tail.next = b;
        return head.next;
    }
    
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null) return head;
        
        ListNode prev = null, slow = head, fast = head;
        while(fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        
        prev.next = null;
        
        ListNode left = sortList(head);
        ListNode right = sortList(slow);
        return merge(left, right);
        
    }
}