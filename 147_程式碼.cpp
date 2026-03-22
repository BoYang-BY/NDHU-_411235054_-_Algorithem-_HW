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
    ListNode* insertionSortList(ListNode* head) {
    if(!head) return head; 

    ListNode* dummy = new ListNode(0);
    ListNode* a = head; 

    while(a) {
        ListNode* c = a->next; 
        ListNode* b = dummy;   

        while(b->next && b->next->val < a->val) {
            b = b->next;
        }

        a->next = b->next;
        b->next = a;

        a = c; 
    }

    return dummy->next;
}
    
};