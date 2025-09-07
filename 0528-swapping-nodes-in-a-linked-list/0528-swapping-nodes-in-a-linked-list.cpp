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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        // find length of list/count of nodes
        while (curr != NULL) {
            count++;
            curr = curr->next;
        }

        // kth node from start
        ListNode* first = head;
        for (int i = 1; i < k; i++) {
            first = first->next;
        }
        // kth node frrom end but (count - k + 1)th node from start
        ListNode* second = head;
        for (int i = 1; i < count - k + 1; i++) {
            second = second->next;
        }

        swap(first->val, second->val);
        return head;
    }
};