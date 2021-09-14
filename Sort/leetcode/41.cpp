// First Missing Positive
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> posList;
        
        for(auto n : nums){
            if(n > 0)
                posList.push_back(n);
        }
        
        for(auto n : posList){
            int idx = abs(n)-1;
            
            if(idx >= posList.size()) continue;
            
            if(posList[idx] > 0){
                posList[idx] *= -1;
            }
        }
        
        for(int idx = 0; idx < posList.size(); idx++){
            if(posList[idx] > 0)
                return idx+1;
        }
        
        return posList.size()+1;
    }
};
