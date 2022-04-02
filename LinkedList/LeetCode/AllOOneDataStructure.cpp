// 432. All O`one Data Structure

class Node {
public:
    Node* prev;
    Node* next;
    unordered_set<string> keys;
    int cnt;

    Node() {
        prev = next = this;
    }

    Node(int _cnt) {
        prev = next = this;
        cnt = _cnt;
    }
};

class AllOne {
public:
    unordered_map<int, Node*> cntNodeMap;
    unordered_map<string, int> keyCntMap;

    Node* head;

    AllOne() {
        head = nullptr;
    }
    
    void inc(string key) {
        int cnt = 0;
        if (keyCntMap.find(key) == keyCntMap.end()) {
            int nextCnt = cnt + 1;
            if (cntNodeMap.find(nextCnt) == cntNodeMap.end()) {
                cntNodeMap[nextCnt] = new Node(nextCnt);
                if (head == nullptr) {
                    head = cntNodeMap[nextCnt];
                } else {
                    cntNodeMap[nextCnt]->prev = head->prev;
                    cntNodeMap[nextCnt]->next = head;
                    head->prev->next = cntNodeMap[nextCnt];
                    head->prev = cntNodeMap[nextCnt];

                    head = cntNodeMap[nextCnt];
                 }
            }
            cntNodeMap[nextCnt]->keys.insert(key);
            keyCntMap[key] = nextCnt;
        } else {
            cnt = keyCntMap[key];
            cntNodeMap[cnt]->keys.erase(key);
            int nextCnt = cnt + 1;
            
            if (cntNodeMap.find(nextCnt) == cntNodeMap.end()) {
                cntNodeMap[nextCnt] = new Node(nextCnt);

                cntNodeMap[cnt]->next->prev = cntNodeMap[nextCnt];
                cntNodeMap[nextCnt]->next = cntNodeMap[cnt]->next;
                cntNodeMap[cnt]->next = cntNodeMap[nextCnt];
                cntNodeMap[nextCnt]->prev = cntNodeMap[cnt];
            }
            
            if (cntNodeMap[cnt]->keys.size() == 0) {
                if (cntNodeMap[cnt] == head) {
                    head = cntNodeMap[nextCnt];
                }
                cntNodeMap[cnt]->prev->next = cntNodeMap[nextCnt];
                cntNodeMap[nextCnt]->prev = cntNodeMap[cnt]->prev;

                cntNodeMap.erase(cnt);
            } 
            cntNodeMap[nextCnt]->keys.insert(key);
            keyCntMap[key]++;
        }
    }
    
    void dec(string key) {
        int cnt = keyCntMap[key];
        int prevCnt = cnt - 1;
        cntNodeMap[cnt]->keys.erase(key);
        keyCntMap[key]--;

        if (prevCnt > 0) {
            if (cntNodeMap.find(prevCnt) == cntNodeMap.end()) {
                cntNodeMap[prevCnt] = new Node(prevCnt);
                
                cntNodeMap[cnt]->prev->next = cntNodeMap[prevCnt];
                cntNodeMap[prevCnt]->prev = cntNodeMap[cnt]->prev;
                cntNodeMap[cnt]->prev = cntNodeMap[prevCnt];
                cntNodeMap[prevCnt]->next = cntNodeMap[cnt];
            }

            if (cntNodeMap[cnt]->keys.size() == 0) {
                if (cntNodeMap[cnt] == head) {
                    head = cntNodeMap[prevCnt];
                }
                cntNodeMap[prevCnt]->next = cntNodeMap[cnt]->next;
                cntNodeMap[cnt]->next->prev = cntNodeMap[prevCnt];

                cntNodeMap.erase(cnt);
            }

            cntNodeMap[prevCnt]->keys.insert(key);
        } else {
            if (cntNodeMap[cnt]->keys.size() == 0) {
                if (cntNodeMap[cnt] != cntNodeMap[cnt]->next) {
                    if (cntNodeMap[cnt] == head) {
                        head = cntNodeMap[cnt]->next;
                    }
                    cntNodeMap[cnt]->prev->next = cntNodeMap[cnt]->next;
                    cntNodeMap[cnt]->next->prev = cntNodeMap[cnt]->prev;
                }
                cntNodeMap.erase(cnt);
            }
            keyCntMap.erase(key);
        }

        if (keyCntMap.size() == 0) {
            head = nullptr;
        }
    }
    
    string getMaxKey() {
        if (head == nullptr) return "";
        int cnt = head->prev->cnt;
        return *cntNodeMap[cnt]->keys.begin();
    }
    
    string getMinKey() {
        if (head == nullptr) return "";
        int cnt = head->cnt;
        return *cntNodeMap[cnt]->keys.begin();
    }
};