class Solution {
public:
    
    int findMinIdx(int l, int r, vector<int>& ratings) {
        int minIdx = l;
        
        for (int i = l+1; i <= r; i++) {
            if (ratings[minIdx] > ratings[i]) {
                minIdx = i;
            }
        }
        
        return minIdx;
    }
    
    void search(int l, int r, vector<int>& ratings, vector<int>& candies) {
        int minIdx = findMinIdx(l, r, ratings);
        
        if (l == r) return;
        
        // update candies
        
        // update left
        for (int i = minIdx-1; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]
               && candies[i] <= candies[i+1]) {
                candies[i] = candies[i+1]+1;
            } else {
                if (i > l) {
                    search(l, i, ratings, candies);                    
                }
                break;
            }
        }
        
        // update right
        for (int i = minIdx+1; i < ratings.size(); i++) {
            if (ratings[i-1] < ratings[i]
               && candies[i-1] >= candies[i]) {
                candies[i] = candies[i-1]+1;
            } else {
                if (i < r) {
                    search(i, r, ratings, candies);                    
                }
                break;
            }
        }
        
        return;
    }
    
    int candy(vector<int>& ratings) {
        int ret = 0;
        
        vector<int> candies(ratings.size(), 1);
        
        search(0, ratings.size()-1, ratings, candies);
        
        for (int candy : candies) {
            ret += candy;
        }
        
        return ret;
    }
};