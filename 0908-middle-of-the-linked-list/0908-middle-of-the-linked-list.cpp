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
    /*
        int getLength(ListNode* head) {
            int len = 0;
            while (head != NULL) {
                len++;
                head = head->next;
            }
            return len;
        }
    */
    ListNode* middleNode(ListNode* head) {
        /*      Method - 1
                int len = getLength(head);
                int ans = (len / 2);

                ListNode* temp = head;
                int cnt = 0;
                while (ans--) {
                    temp = temp->next;
                    cnt++;
                }
                return temp;
        */

        // slow and fast pointer
        if (head == NULL && head->next == NULL) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};