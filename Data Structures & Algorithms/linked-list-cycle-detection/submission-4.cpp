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
    bool hasCycle(ListNode* head) {
        if(head==NULL) return 0;
        ListNode* slow = head;
        ListNode* fast = head;
        if(fast->next == NULL) return 0;
        if(fast->next->next == slow) return 1;
        while(slow->next != NULL && fast->next != NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return 1;
            }
        }
        return 0;
    }
};
