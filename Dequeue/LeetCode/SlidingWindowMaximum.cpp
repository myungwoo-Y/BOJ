// Title : 239. Sliding Window Maximum

// Used deque as ds
// Remove redundant elements using map

// Intuition
// if the el is bigger than front, reset dequeue and insert the el
// if the el is less than back, remove small elements and insert the el to back
// in other cases, just insert the el to back

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = 0;
        
        deque<int> dq;
        vector<int> ret;
        unordered_map<int, int> m;
        
        while(r < nums.size()){
            int re = nums[r++];
        
            // remove el from map
            if(r > k){
                int le = nums[l];
                if(m[le] > 0) m[le]--;
                l++;
                
                // remove zero count el
                while(!dq.empty() && m[dq.front()] <= 0){
                    dq.pop_front();
                }
                while(!dq.empty() && m[dq.back()] <= 0){
                    dq.pop_back();
                }
            }
            
            if(dq.empty()){
                dq.push_back(re);
                m[re]++;
            }else{
                if(re > dq.front()){
                    while(!dq.empty()){
                        dq.pop_front();
                    }
                    dq.push_front(re);
                    m[re]++;
                }else{
                    while(re > dq.back()){
                        dq.pop_back();
                    }
                    if(re != dq.back())
                        dq.push_back(re);
                    m[re]++;
                }
            }
            
            // find max
            if(r >= k && !dq.empty()){
                ret.push_back(dq.front());
            }
        }
        return ret;
    }
};