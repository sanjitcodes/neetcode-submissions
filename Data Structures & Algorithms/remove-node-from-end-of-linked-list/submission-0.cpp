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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* tmp = head;
        while(tmp != NULL){
            tmp = tmp->next;
            ++len;
        }
        n = len - n + 1;
        if(n == 1){
            tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        tmp = head;
        ListNode* prev = NULL;
        for(int i=1; i<n; i++){
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = tmp->next;
        tmp->next = NULL;
        delete(tmp);
        return head;

    }
};
