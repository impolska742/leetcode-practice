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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode aNodePrev = null, bNode = null, listHead = null;
        ListNode curr = list1;
        int cnt = 0;
        while(curr != null) {
            if(aNodePrev != null && bNode != null) break;
            if(cnt == a - 1) aNodePrev = curr;
            if(cnt == b) bNode = curr;
            if(cnt != b && listHead == null) listHead = curr;
            // System.out.print(curr.val + " ");
            curr = curr.next;
            cnt++;
        }
        
        aNodePrev.next = list2;
        curr = list2;
        while(curr.next != null) {
            curr = curr.next;
        }
        
        curr.next = bNode.next;
        return listHead;
    }
}