// Remove Nth Node From End of List
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
    ListNode* endNode = nullptr;
    int nth = 0;
    bool isRemove = false;
    
    void removeNextNode(ListNode* head){
        ListNode* nextNode = head->next;
        if(nextNode->next == nullptr){
            head->next = nullptr;
        }else{
            head->next = nextNode->next;
        }
    }
    
    int startRemove(ListNode* head, int size){
        if(head->next == nullptr){
            endNode = head;
            return size;
        }else{
            int totalSize = startRemove(head->next, size+1);
            int childSize = totalSize - size;
            
            if(childSize == nth){
                removeNextNode(head);
                isRemove = true;
            }
            return totalSize;
        }
    }
    
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr){
            return nullptr;
        }else{
            nth = n;
            startRemove(head, 1);
            
            if(!isRemove){
                head = head->next;
            }
            
        }
        return head;
    }
};