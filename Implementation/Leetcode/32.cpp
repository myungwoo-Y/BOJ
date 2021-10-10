// 32. Longest Valid Parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int leftSum = 0, rightSum = 0;
        
        int maxLen = 0;
        
        // start traversing the strings from the left towards the right
        for (int i = 0; i < s.length(); i++) {
            if(s[i] == ')')
                rightSum++;
            else
                leftSum++;
            
            if(leftSum < rightSum){
                rightSum = 0;
                leftSum = 0;
            }else if(leftSum == rightSum){
                maxLen = max(maxLen, leftSum*2);
            }
        }
        
        
        // start traversing the strings from the right towards the left
        leftSum = 0;
        rightSum = 0;
        for (int i = s.length()-1; i >= 0; i--) {
            if(s[i] == ')')
                rightSum++;
            else
                leftSum++;
            
            if(leftSum > rightSum){
                rightSum = 0;
                leftSum = 0;
            }else if(leftSum == rightSum){
                maxLen = max(maxLen, leftSum*2);
            }
        }
        
        return maxLen;
    }
};
