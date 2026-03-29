class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* mid = NULL;

        while(fast != NULL && fast->next != NULL){
            mid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        mid->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow); 

        return mergeList(left, right);   
    }

    ListNode* mergeList(ListNode* L1, ListNode* L2){

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (L1 != NULL && L2 != NULL){
            if(L1->val < L2->val){
                current->next = L1;
                L1 = L1->next;
            }else{
                current->next = L2;
                L2 = L2->next;
            }
            current = current->next; 
        }

        if(L1 != NULL)
            current->next = L1;
        else
            current->next = L2;

        return dummy->next;
    }
};