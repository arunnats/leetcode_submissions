class LRUCache {
public:

    class node{
        public:
            int key;
            int val;
            node* prev;
            node* next;

            node(int _key, int _val){
                key = _key;
                val = _val;
            }
    };

    node * head = new node(-1, -1);
    node * tail = new node(-1, -1);

    int cap;
    unordered_map < int, node * > cache;

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addnode( node* newnode) {
        node* temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            node* resnode = cache[key];
            int res = resnode->val;
            cache.erase(key);

            deletenode(resnode);
            addnode(resnode);
            cache[key] = head->next;

            return res;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            node* existingnode = cache[key];
            cache.erase(key);
            deletenode(existingnode);
        }

        if (cache.size() == cap) {
            cache.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key, value));
        cache[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */