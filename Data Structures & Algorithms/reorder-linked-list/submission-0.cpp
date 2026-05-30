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
    ListNode* reverseList(ListNode* head){
        if(head==NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur != NULL){
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }   
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode* tmp = head;
        while(tmp != NULL){
            tmp = tmp->next;
            ++n;
        }
        if(n < 3){
            return;
        }

        int break_point = (n % 2 == 0) ? n/2 -1 : n/2;
        tmp = head;
        for(int i=1; i<=(break_point); i++){
            tmp = tmp->next;
        }
        ListNode* list1 = head;
        ListNode* list2 = tmp->next;
        tmp->next = NULL;

        list2 = reverseList(list2);

        tmp = list1;
        while(tmp!=NULL && list2 != NULL){
            ListNode* bkp1 = tmp->next;
            ListNode* bkp2 = list2->next;
            tmp->next = list2;
            list2->next = bkp1;
            list2 = bkp2; 
            tmp = bkp1;
        }

    }
};
