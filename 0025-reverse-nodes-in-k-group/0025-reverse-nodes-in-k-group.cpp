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
/* recursion 
private:
    ListNode* reverse(ListNode* curr, ListNode* end) {
        ListNode* prev = NULL;
        while (curr != end) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
*/

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        /* recursion method
        if (head == 0 || head->next == NULL) {
            return head;
        }

        ListNode* tail = head;
        for (int i = 0; i < k; i++) {
            if (!tail)
                return head;
            tail = tail->next;
        }
        ListNode* newHead = reverse(head, tail);
        head->next = reverseKGroup(tail, k);
        return newHead;

        */

        if (head == nullptr || k == 1) {
            return head;
        }

        ListNode* current = head;
        ListNode* next_node = nullptr;
        ListNode* prev = nullptr;
        int count = 0;

        ListNode* temp_checker = head;
        for (int i = 0; i < k; ++i) {
            if (temp_checker == nullptr) {
                return head;
            }
            temp_checker = temp_checker->next;
        }

        while (current != nullptr && count < k) {
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
            count++;
        }

        if (next_node != nullptr) {
            head->next = reverseKGroup(next_node, k);
        }

        return prev;
    }
};