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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int count = 0;
        ListNode curr = head;
        ListNode prev = null;
        while(curr != null) {
            count++;
            curr = curr.next;
        }
        
        if(n == count) {
            head = head.next;
            return head;
        } 
        
        curr = head;
        int k = 0;
        
        while(curr != null) {
            k++;
            if(k == count - n + 1) 
                prev.next = curr.next;
            else 
                prev = curr;
            curr = curr.next;
        }
        
        return head;
    }
}