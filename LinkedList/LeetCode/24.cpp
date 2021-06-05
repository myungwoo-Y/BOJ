// Swap Nodes in Pairs
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

using namespace std;
class Solution {
public:
    
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return nullptr;
        
        ListNode* ret = head->next != nullptr ? head->next : head;
        
        ListNode* curHead = head;
        ListNode* back = nullptr;
        while(curHead != nullptr && curHead->next != nullptr){
            ListNode* first = curHead;
            ListNode* second = curHead->next;
            
            if(second == nullptr) break;
            
            first->next = second->next;
            second->next = first;
            
            
            if(back != nullptr){
                back->next = second;
            }
            back = first;
            curHead = first->next;
        }
        return ret;
    }
};