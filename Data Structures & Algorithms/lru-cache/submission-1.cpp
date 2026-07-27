class Node {
public:
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = next = nullptr;
    }
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> mp;

    Node *head;
    Node *tail;

    void remove(Node *node) {
        Node *p = node->prev;
        Node *n = node->next;

        p->next = n;
        n->prev = p;
    }

    void insert(Node *node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        Node *node = mp[key];

        remove(node);
        insert(node);

        return node->val;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            remove(mp[key]);
            delete mp[key];
        }

        Node *node = new Node(key, value);

        mp[key] = node;
        insert(node);

        if (mp.size() > cap) {

            Node *lru = tail->prev;

            remove(lru);

            mp.erase(lru->key);

            delete lru;
        }
    }
};