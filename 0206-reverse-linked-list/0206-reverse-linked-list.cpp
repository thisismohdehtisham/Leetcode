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
    void reverse(ListNode*& head,ListNode* curr,ListNode* prev){
        // base case
        if(curr == NULL){
            head = prev;
            return;
        }

        ListNode* forward = curr -> next;
        reverse(head, forward, curr);
        curr -> next = prev;

    }

    ListNode* reverseList(ListNode* head) {
        // recursive approach
        ListNode* curr = head;
        ListNode* prev = NULL;

        reverse(head, curr, prev);
        return head;



        /* while loop approach
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
        */
    }
};