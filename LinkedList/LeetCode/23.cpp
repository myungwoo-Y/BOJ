// Merge k Sorted Lists
struct ListNode {
   int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* ret = new ListNode();
        ListNode* cur = new ListNode();
        ret->next = cur;
        while(a != nullptr || b != nullptr){
            if(a != nullptr && b != nullptr){
                if(a->val < b->val){
                    cur->next = new ListNode(a->val);
                    a = a->next;
                    cur = cur->next;
                }else{
                    cur->next = new ListNode(b->val);
                    b = b->next;
                    cur = cur->next;
                }
            }else if(a == nullptr){
                cur->next = new ListNode(b->val);
                b = b->next;
                cur = cur->next;
            }else{
                cur->next = new ListNode(a->val);
                a = a->next;
                cur = cur->next;
            }
        }
        return ret->next->next;
    }
    
    ListNode* sort(vector<ListNode*>& list, int l, int r){
        if(l == r) return list[l];
        
        int mid = (l+r) / 2;
        ListNode* leftList = sort(list, l, mid);
        ListNode* rightList = sort(list, mid+1, r);
        
        ListNode* ret = merge(leftList, rightList);
        
        return ret;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        
        return sort(lists, 0, lists.size()-1);
    }
};