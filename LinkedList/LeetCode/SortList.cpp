class Solution {
public:
    ListNode* splitListByMid(ListNode* head) {
        ListNode* fast = head;
        ListNode* late = head;
        ListNode* prev = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            prev = late;
            late = late->next;
            fast = fast->next->next;
        }
        
        if (prev != nullptr) {
            prev->next = nullptr;  
        }
        
        return late;
    }
    
    
    ListNode* mergeSort(ListNode* head) {
        ListNode* left = head;
        ListNode* right = splitListByMid(head);
        
        if (left == right) {
            return left;
        }
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        ListNode* sortedHead = new ListNode(0);
        ListNode* tail = sortedHead;
        
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        
        if (left == nullptr) {
            tail->next = right;
        } else {
            tail->next = left;
        }
        
        return sortedHead->next;
    }
    
    
    ListNode* sortList(ListNode* head) {
        
        ListNode* sortedHead = mergeSort(head);
        
        return sortedHead;
    }
};