class LFUCache {
    struct ListNode {
        int key;
        int val;
        int freq;
        ListNode* prev;
        ListNode* next;

        ListNode(int k, int v) {
            key = k;
            val = v;
            freq = 1;
            prev = nullptr;
            next = nullptr;
        } 
    };

    struct LinkedList {
        ListNode* left;
        ListNode* right;
        int size;

        LinkedList() {
            left = new ListNode(0, 0);
            right = new ListNode(0, 0);
            left->next = right;
            right->prev = left;
            size = 0;
        }

        ~LinkedList() {
            delete left;
            delete right;
        }

        int length() {
            return size;
        }

        // Insert after left (MRU)
        void pushFront(ListNode* node) {
            ListNode* nxt = left->next;

            left->next = node;
            node->prev = left;

            node->next = nxt;
            nxt->prev = node;

            size++;
        }

        // Remove a given node
        void pop(ListNode* node) {
            ListNode* prv = node->prev;
            ListNode* nxt = node->next;

            prv->next = nxt;
            nxt->prev = prv;

            node->prev = nullptr;
            node->next = nullptr;

            size--;
        }

        // Remove LRU node (before right)
        ListNode* popBack() {
            if (size == 0)
                return nullptr;

            ListNode* node = right->prev;
            pop(node);
            return node;
        }
    };

    int capacity;
    int lfuCount;
    //each frequency has its own LL
    unordered_map<int, ListNode*> nodeMap;
    unordered_map<int, LinkedList*> listMap;

    void updateFreq(ListNode* node) {
        int freq = node->freq;

        listMap[freq]->pop(node);

        if (freq == lfuCount && listMap[freq]->length() == 0)
            lfuCount++;

        node->freq++;

        if (!listMap.count(node->freq))
            listMap[node->freq] = new LinkedList();

        listMap[node->freq]->pushFront(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        lfuCount = 0;
    }

    ~LFUCache() {
        for (auto &p : nodeMap)
            delete p.second;

        for (auto &p : listMap)
            delete p.second;
    }

    int get(int key) {
        if (!nodeMap.count(key))
            return -1;

        ListNode* node = nodeMap[key];
        updateFreq(node);

        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (nodeMap.count(key)) {
            ListNode* node = nodeMap[key];
            node->val = value;
            updateFreq(node);
            return;
        }

        if (nodeMap.size() == capacity) {
            ListNode* node = listMap[lfuCount]->popBack();
            nodeMap.erase(node->key);
            delete node;
        }

        ListNode* node = new ListNode(key, value);

        nodeMap[key] = node;

        if (!listMap.count(1))
            listMap[1] = new LinkedList();

        listMap[1]->pushFront(node);

        lfuCount = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */