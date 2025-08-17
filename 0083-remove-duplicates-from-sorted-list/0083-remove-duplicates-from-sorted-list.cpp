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
        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        ListNode* curr = head;

        while(curr != nullptr){
            if((curr->next != nullptr) && curr->val == curr->next->val){
                ListNode* duplicate_next = curr->next->next;
                ListNode* nodetodelete = curr->next;
                curr->next = duplicate_next;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
};