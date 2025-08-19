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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // recursive approach => SC - O(m+n), TC - O(m+n)
        /*
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        if(list1->val <= list2->val){
            list1 -> next = mergeTwoLists(list1->next, list2);
            return list1;
        }else{
            list2 -> next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        SC - O(m+n), TC - O(m+n)
        */
        // iterative approach => SC - O(1), TC - O(m+n)
        ListNode dummy(0);
        ListNode* curr = &dummy;

        // Traverse both lists, adding the smaller node to the new list.
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        // Attach any remaining nodes from the non-empty list.
        if (list1 != nullptr) {
            curr->next = list1;
        } else if (list2 != nullptr) {
            curr->next = list2;
        }

        // Return the head of the merged list (the node after the dummy).
        return dummy.next;
    }

};