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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int max_sum = 0;

        // find middle
        while(fast){
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse the half linked list
        ListNode* forward, *prev = NULL;
        while(slow){
            forward = slow->next;
            slow->next = prev;
            prev = slow;
            slow = forward;
        }

        // get max sum of twins
        while(prev){
            max_sum = max(max_sum, head->val + prev->val);
            prev = prev->next;
            head = head->next;
        }
        return max_sum;
    }
};