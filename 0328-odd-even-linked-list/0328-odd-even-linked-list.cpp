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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* oddDummy = new ListNode(0);
        ListNode* evenDummy = new ListNode(0);

        ListNode* odd = oddDummy;
        ListNode* even = evenDummy;

        int pos = 1;
        while (head) {
            if (pos % 2 == 1) {
                odd->next = head;
                odd = odd->next;
            } else {
                even->next = head;
                even = even->next;
            }
            head = head->next;
            pos++;
        }

        // terminate even list
        even->next = nullptr;

        // merge odd and even
        odd->next = evenDummy->next;

        return oddDummy->next;
    }
};