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
    public ListNode swapNodes(ListNode head, int k) {
        int count = 0;
        ListNode curr = head;
        ListNode start = null, end = null;
        while(curr != null) {
            count++;
            curr = curr.next;
        }
        
        curr = head;
        int cnt2 = 0;
        while(curr != null) {
            cnt2++;
            if(cnt2 == k && start == null) start = curr;
            if(cnt2 == count - k + 1 && end == null) end = curr;
            if(start != null && end != null) break;
            curr = curr.next;
        }
        
        
        int temp = start.val;
        start.val = end.val;
        end.val = temp;
        
        return head;
    }
}