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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr != NULL){
            bool is_duplicate = false;

            while(curr->next && curr->val == curr->next->val){
                is_duplicate = true;
                curr = curr->next;
            }

            if(is_duplicate){
                prev->next = curr->next;
            }else{
                prev = prev->next;
            }

            curr = curr->next;
        }

        return dummy->next;
    }
};