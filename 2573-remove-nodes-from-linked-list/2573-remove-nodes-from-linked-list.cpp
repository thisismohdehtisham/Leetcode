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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        if (!head) return nullptr;

        // Step 1: Reverse list
        ListNode* revHead = reverseList(head);

        // Step 2: Traverse with two pointers
        ListNode* prev = revHead;
        ListNode* curr = revHead->next;

        while (curr) {
            if (curr->val < prev->val) {
                // Remove curr
                prev->next = curr->next;
                // delete curr; // free memory
            } else {
                prev = curr;
            }
            curr = prev->next;
        }

        // Step 3: Reverse back
        return reverseList(revHead);
    }
};