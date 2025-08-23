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
    void reorderList(ListNode* head) {
        if (!head) return;
        //TC - O(n) + O(n/2) + O(n) = O(n), SC - O(1)

        // middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse
        ListNode* second = slow->next;
        slow->next = NULL;
        ListNode* node = NULL;

        while(second){
            ListNode* temp = second->next;
            second->next = node;
            node = second;
            second = temp;
        }

        //merge the two halves
        ListNode* first = head;
        second = node;
        while(second){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};