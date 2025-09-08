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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // create a vector to store k parts
        vector<ListNode*> parts(k, NULL);

        int len = 0;
        for(ListNode* node = head; node; node = node->next) len++;

        // calculate the min part size(n) and the extra nodes(r)
        int n = len / k, r = len % k;

        ListNode* node = head, *prev = NULL;
        // loop through each part 
        for(int i=0; node && i < k; i++, r--){
            parts[i] = node; //store the current node as the start of the current part
            // traverse n+carry nodes if extra else only n nodes
            for(int j = 0; j<n + (r > 0); j++){
                prev = node;
                node = node -> next;
            }
            prev-> next = NULL; // disconnect the current part from the rest of the list 
        }
        return parts;
        
    }
};