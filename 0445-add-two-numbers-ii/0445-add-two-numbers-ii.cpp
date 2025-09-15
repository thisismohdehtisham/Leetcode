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
    ListNode* reversell(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rl1 = reversell(l1);
        ListNode* rl2 = reversell(l2);

        ListNode* dummy = new ListNode(NULL);
        ListNode* curr = dummy;
        ListNode* temp1 = rl1;
        ListNode* temp2 = rl2;
        int carry = 0;

        while(temp1 != NULL || temp2 != NULL){
            int sum = carry;
            if(temp1) sum += temp1->val;
            if(temp2) sum += temp2->val;

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            curr->next = newNode;
            curr = curr->next;

            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }

        return reversell(dummy->next);

    
    }
};