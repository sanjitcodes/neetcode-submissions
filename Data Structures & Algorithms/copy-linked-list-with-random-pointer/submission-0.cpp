/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        Node* headnew = new Node(0);
        unordered_map<Node*, Node*> m;
        Node* tmp = head;
        Node* bkp1 = headnew;
        while(tmp != NULL){
            Node* nxt = new Node(tmp->val);
            m[tmp] = nxt;
            headnew->next = nxt;
            headnew = nxt;
            tmp = tmp->next;
        }
        bkp1 = bkp1->next;
        tmp = bkp1;
        Node* old = head;
        while(tmp != NULL){
            if (old->random != NULL) {
                tmp->random = m[old->random];
            }
            tmp = tmp->next;
            old = old->next;
        }
        return bkp1;

    }
};
