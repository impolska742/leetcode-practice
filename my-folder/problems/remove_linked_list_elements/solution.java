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
    public ListNode removeElements(ListNode head, int val) {
        if(head == null) return head;
      
        ListNode curr = head;
        ListNode prev = null;
        ListNode currHead = null;
        while(curr != null) {
            if(curr.val != val) {
                if(currHead == null) currHead = curr;
                prev = curr;
                curr = curr.next;
            } 
            
            else {
                if(prev != null)
                    prev.next = curr.next;
                curr = curr.next;
            }
        }
        
        return currHead;
    }
}