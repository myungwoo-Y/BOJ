class Node {
public:
    Node* prev;
    Node* next;
    int val, cnt;
    
    Node(int _cnt) {
        prev= nullptr;
        next = nullptr;
        cnt = _cnt;
    }
    
    Node(int _val, int _cnt, Node* _prev, Node* _next) {
        prev = _prev;
        next = _next;
        val = _val;
        cnt = _cnt;
    }
};

struct cmp {
    bool operator()(Node* a, Node* b) const {
        if (a->val != b->val) {
            return a->val > b->val;
        } else {
            return a->cnt > b->cnt;
        }
    };
};


class MaxStack {
public:
    set<Node*, cmp> s;
    unordered_set<Node*> delSet;
    Node* head;
    int cnt = 0;
    
    MaxStack() {
        head = new Node(cnt++);
    }
    
    void push(int x) {
        Node* newNode = new Node(x, cnt++, nullptr, head);
        head->prev = newNode;
        head = newNode;
        s.insert(newNode);
    }
    
    int pop() {
        Node* delNode = head;
        head = head->next;
        head->prev = nullptr;
        s.erase(delNode);
        return delNode->val;
    }
    
    int top() {
        return head->val;
    }
    
    int peekMax() {
        return (*s.begin())->val;
    }
    
    int popMax() {
        Node* delNode = *(s.begin());
        if (delNode->prev != nullptr) {
            delNode->prev->next = delNode->next;
        }
        if (delNode->next != nullptr) {
            delNode->next->prev = delNode->prev;
        }
        if (head == delNode) {
            head = delNode->next;
        }
        s.erase(delNode);
        
        return delNode->val;
    }
};