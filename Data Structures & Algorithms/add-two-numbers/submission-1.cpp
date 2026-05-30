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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;
        int carry = 0;
        int sum = 0;
        ListNode* bkp;
        while(l1 != NULL || l2 != NULL){
            sum = (l1 != NULL) ? l1->val : 0; 
            sum += (l2 != NULL) ? l2->val: 0;
            ListNode* n = new ListNode((sum+carry) % 10);
            carry = (sum + carry)/10;
            if(result == NULL){
                result = n;
                bkp = result;
            } 
            else{
                result->next = n;
                result = result->next;
            }
            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }

        if(carry){
            ListNode* n = new ListNode(carry);
            result->next = n;
        }
        return bkp;
    }
};
