/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0,b = 0;
        ListNode *curr = headA;
        while(curr != NULL) {
            a++;
            curr = curr->next;
        }
        
        curr = headB;
        while(curr != NULL) {
            b++;
            curr = curr->next;
        }
            
        if(a != b) {
            int c = 0;
            curr = (a > b) ? headA : headB;
            while(c < abs(a - b) and curr != NULL) {
                curr = curr->next;
                c++;
            } 
        }
        
        ListNode *x = NULL;
        ListNode *y = NULL;
        
        if(a < b) {
            x = curr;
            y = headA;
        } else if(b < a) {
            x = curr;
            y = headB;
        } else {
            x = headA;
            y = headB;
        }
        
        while(x != NULL and y != NULL) {
            if(x == y) {
                return x;
            }
            x = x->next;
            y = y->next;
        }
        
        return NULL;
            
    }
};