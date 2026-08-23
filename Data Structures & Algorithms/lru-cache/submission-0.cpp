class Node {
   public:
    int val;
    Node* next;
    Node* prev;
    int key;

    Node(int v, int k) {
        val = v;
        next = nullptr;
        prev = nullptr;
        key = k;
    }
};

class LRUCache {
   public:
    int cap, size = 0;
    unordered_map<int, Node*> data;

    Node* head ;
    Node* tail ;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void insertAfterHead(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        node->prev = head;

        node->next = nextNode;
        nextNode->prev = node;
    }

    int get(int key) {
        if (data.find(key) != data.end()) {
            Node* curr = data[key];
            removeNode(curr);
            insertAfterHead(curr);
            return curr->val;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (data.find(key) != data.end()) {
            Node* curr = data[key];
            removeNode(curr);
            insertAfterHead(curr);
            curr->val = value;
            return;
        }
        size++;
        Node* dll = new Node(value, key);
        data[key] = dll;
        insertAfterHead(dll);
        if (size > cap) {
            Node *de = tail->prev;
            data.erase(de->key);
            removeNode(de);
            delete de;
            size--;
        }
    }
};
