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
    int getDecimalValue(ListNode* head) {
        ListNode *tmp = head;
        int sz = 0;
        while(tmp != NULL) {
            sz++;
            tmp = tmp->next;
        }
        tmp = head;
        int num = 0;
        sz--;
        while(tmp != NULL) {
            num += pow(2, sz) * tmp->val;
            sz--;
            tmp = tmp->next;
        }
        
        return num;
    }
};