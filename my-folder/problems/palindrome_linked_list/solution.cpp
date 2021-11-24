/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode *slow, ListNode *prevSlow) {
        ListNode *curr = slow;
        ListNode *prev = NULL;
        while(curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        prevSlow->next = prev;
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast->next != NULL and fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *b = reverse(slow->next, slow);
        ListNode *a = head;
        
        while(a != NULL and b != NULL) {
            if(a -> val != b->val) {
                return false;
            }
            a = a->next;
            b = b->next;
        }
        return true;
    }
};