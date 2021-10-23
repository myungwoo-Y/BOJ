// Title : Largest Rectangle in Histogram

// 1. recursion
// find min index representing i
// get left max and right max
// compare left max and right max and find largest rectangle
// compare largest rectangle and the area that is calculated by height[i] * range(l to r)
class Solution1 {
public:
    
    int search(int l, int r, vector<int>& heights){
        if(l > r) return 0;
        if(l == r) return heights[l];
        
        int minIdx = l;
        
        for (int i = l; i <= r; i++) {
            if(heights[i] < heights[minIdx]) minIdx = i;
        }
        
        int lm = search(l, minIdx-1, heights);
        int rm = search(minIdx+1, r, heights);
        
        return max({lm, rm, heights[minIdx] * (r-l+1)});
    }
    
    int largestRectangleArea(vector<int>& heights) {
        return search(0, heights.size()-1, heights);
    }
};


// 2. stack
// How to insert the element to stack?
// Insert from 0
// Pop condition ?
// Pop if el is less than top
// Caluclate max value in each poping
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        
        // It is valid at 0 when there are no zero height
        int validEndIdx = 0;
        
        int ret = *max_element(heights.begin(), heights.end());
        for (int i = 0; i < heights.size(); i++) {
            if(!st.empty() && st.top().second > heights[i]){
                auto start = st.top();
                
                while(!st.empty() && st.top().second >= heights[i]){
                    auto el = st.top();
                    st.pop();
                    
                    auto beforeIdx = st.empty() ? validEndIdx : st.top().first;
                    
                    if(el.first - beforeIdx > 1 || st.empty()){
                        ret = max(ret, (start.first-beforeIdx+(heights[beforeIdx] >= el.second)) * el.second);
                    }else{
                        ret = max(ret, (start.first-el.first+1) * el.second);
                    }
                }
            }
            if(heights[i] == 0)
                validEndIdx = i+1;
            else
                st.push({i, heights[i]});
        }
        
        if(st.empty()){
            return ret;
        }
        else{
            auto start = st.top();
            while(!st.empty()){
                auto el = st.top();
                st.pop();
                
                auto beforeIdx = st.empty() ? validEndIdx : st.top().first;
                
                if(el.first - beforeIdx > 1 || st.empty()){
                    ret = max(ret, (start.first-beforeIdx+(heights[beforeIdx] >= el.second)) * el.second);
                }else{
                    ret = max(ret, (start.first-el.first+1) * el.second);
                }
            }
            return ret;
        }
    }
};