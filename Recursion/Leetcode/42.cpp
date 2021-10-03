//Title : Trapping Rain Water

//1. find the min value between left and right, then compute how much water it can trap
//2. if no, find the max value and run a recur fun on left section and right section
class Solution {
public:
    
    // select l or b and sum each block
    int getSubTrap(int l, int r, vector<int>& height){
        
        if (r-l < 2) return 0;
    
        int base = min(height[l], height[r]);
        
        int sum = 0;
        for (int i = l+1; i <= r-1; i++) {
            if(height[i] > base)
                return -1;
            else
                sum += base - height[i];
        }
        
        return sum;
    }
    
    int getTrap(int l, int r, vector<int>& height){
        int sum = getSubTrap(l, r, height);
        
        if(sum != -1) return sum;
        
        int maxIdx = l+1;
        for (int i = l+1; i <= r-1; i++) {
            if(height[maxIdx] < height[i])
                maxIdx = i;
        }
        
        return getTrap(l, maxIdx, height) + getTrap(maxIdx, r, height);
        
    }
    
    int trap(vector<int>& height) {
        return getTrap(0, height.size()-1, height);
    }
};