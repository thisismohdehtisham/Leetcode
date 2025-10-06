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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        ListNode* curr = head->next;
        int sum = 0;

        while(curr){
            if(curr->val == 0){
                prev->next = new ListNode(sum);
                prev = prev->next;
                sum = 0;
            }else{
                sum = sum + curr->val;
            }
            curr = curr->next;

        }
        return dummy->next;

        // ListNode* dummy = new ListNode(0);
        // ListNode* tail = dummy;
        // ListNode* curr = head->next; // skip the first 0
        // int sum = 0;

        // while (curr) {
        //     if (curr->val == 0) {
        //         // segment ended, create node
        //         tail->next = new ListNode(sum);
        //         tail = tail->next;
        //         sum = 0;
        //     } else {
        //         sum += curr->val;
        //     }
        //     curr = curr->next;
        // }

        // return dummy->next;
    }
};