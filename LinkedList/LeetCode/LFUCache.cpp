// Title : 460. LFU Cache
struct Node {
    int key, value, freq;
    Node* pre;
    Node* next;
};

class DLinkedList {
public:
    Node* sentinel;
    int size;
    
    DLinkedList() {
        sentinel = new Node({0, 0, 0, nullptr, nullptr});
        sentinel->pre = sentinel->next = sentinel;
        size = 0;
    }
    
    void append(Node* node) {
        node->next = sentinel->next;
        node->pre = sentinel;
        sentinel->next->pre = node;
        sentinel->next = node;
        if (sentinel->pre == sentinel) sentinel->pre = node;
        size++;
    }
    
    Node* pop(Node* node = nullptr) {
        if (size == 0) return nullptr;
        
        if (node == nullptr) node = sentinel->pre;
        node->pre->next = node->next;
        node->next->pre = node->pre;
        
        size--;
        
        return node;
    }
};

class LFUCache {
public:
    int Capacity;
    unordered_map<int, Node*> keyMap;
    unordered_map<int, DLinkedList*> freqMap;
    int minFreq;
    int cnt;
    
    LFUCache(int capacity) {
        Capacity = capacity;
        cnt = 0;
        minFreq = INT32_MAX;
    }
    
    int get(int key) {
        if (Capacity == 0 || keyMap.find(key) == keyMap.end()) {
            return -1;
        } else {
            auto node = keyMap[key];
            update(key, node->value);
            return node->value;
        }
    }
    
    void put(int key, int value) {
        if (Capacity == 0) return;
        if (keyMap.find(key) == keyMap.end()) {
            int freq = 1;
            Node* node = new Node({key, value, freq, nullptr, nullptr});
            if (cnt >= Capacity) deleteMinPreq();
            if (freqMap.find(freq) == freqMap.end()) freqMap[freq] = new DLinkedList();
            freqMap[freq]->append(node);
            
            keyMap[key] = node;
            minFreq = 1;
            cnt++;
        } else {
            update(key, value);
        }
    
    }
    
    void deleteMinPreq() {
        if (cnt == 0) return;
        auto dl = freqMap[minFreq];
        auto deletedNode = dl->pop();
        
        if (deletedNode != nullptr) {
            keyMap.erase(deletedNode->key);
            delete deletedNode;
            deletedNode = nullptr;
        }
    }
    
    void update(int key, int value) {
        auto node = keyMap[key];
        int newFreq = node->freq + 1;
        node->value = value;
        
        freqMap[node->freq]->pop(node);

        if (freqMap.find(newFreq) == freqMap.end()) freqMap[newFreq] = new DLinkedList();
        freqMap[newFreq]->append(node);
        
        // update Freq
        if (minFreq == node->freq && freqMap[node->freq]->size == 0)
            minFreq++;
        
        node->freq = newFreq;
    }
};