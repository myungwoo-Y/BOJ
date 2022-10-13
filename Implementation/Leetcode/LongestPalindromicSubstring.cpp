class Solution {
public:
    
    int getPalin(int l, int r, string& s) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        
        return r-l - 1;
    }
    
    string longestPalindrome(string s) {
        string ret = "";
        int start = 0, palinLength = 0;
        
        for (int mid = 0; mid < s.length(); mid++) {
            int newPalinLength = getPalin(mid, mid, s);
            
            if (mid+1 < s.length() && s[mid] == s[mid+1]) {
                newPalinLength = max(newPalinLength, getPalin(mid, mid+1, s));
            }
            
            if (newPalinLength > palinLength) {
                start = mid - (newPalinLength - 1) / 2;
                palinLength = newPalinLength;
            }
        }
        
        return s.substr(start, palinLength);
    }
};