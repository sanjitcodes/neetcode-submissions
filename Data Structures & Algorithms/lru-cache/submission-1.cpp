class ListNode{
public:
    int key;
    int value;
    ListNode* next;
    ListNode* prev;
    ListNode(int key_, int value_){
        key = key_;
        value = value_;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
    // map of key,addres
    unordered_map<int, ListNode* > map;
    ListNode* head;
    ListNode* tail;
    int capacity;

public:
    LRUCache(int capacity_) {
        capacity = capacity_;
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->prev = head;    
    }
    
    int get(int key) {
        if(map.find(key) != map.end()){
            ListNode* address = map[key];
            
            // make it recently used
            // place in in the beginning
            
            address->prev->next = address->next;
            address->next->prev = address->prev;

            address->next = head->next;
            head->next->prev = address;
            head->next = address;
            address->prev = head;

            return address->value;

        }
        return -1;
    }
    
    void put(int key, int value) {
        
        // if already present

        if(map.find(key) != map.end()){
            ListNode* address = map[key];
            
            // make it recently used
            // place in in the beginning
            
            address->prev->next = address->next;
            address->next->prev = address->prev;

            address->next = head->next;
            head->next->prev = address;
            head->next = address;
            address->prev = head;

            // updating the value of the node
            address->value = value;
            return;
        }

        // if absent
        if(map.size() == capacity){
            // remove element from cache and then insert
            ListNode* rem = tail->prev;
            map.erase(rem->key);
            rem->prev->next = tail;
            tail->prev = rem->prev;
            delete(rem);
        }
        // new direct insertion
        ListNode* newNode = new ListNode(key, value);
        map[key] = newNode;

        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
        newNode->prev = head;

        return;
        
    }
};
