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
    ListNode* rotateRight(ListNode* head, int k) {
        /*
        if(head == 0 || head->next == 0 || k == 0){
            return head;
        }

        int len = 1;
        ListNode* tail;

        for(tail = head; tail->next; tail = tail->next){
            len++;
            
        } 
        tail->next = head;

        int t = len - (k % len);

        for(int i = 0; i< t; i++){
            tail = tail->next;
        }

        ListNode* newHead = tail->next;
        tail->next = NULL;
        return newHead;
        */

        if (!head) return head;

        int length = 1;
        ListNode* dummy = head;

        while (dummy->next) {
            dummy = dummy->next;
            length++;
        }

        int position = k % length;
        if (position == 0) return head;

        ListNode* current = head;
        for (int i = 0; i < length - position - 1; ++i) {
            current = current->next;
        }

        ListNode* newHead = current->next;
        current->next = nullptr;
        dummy->next = head;

        return newHead;
    }
};