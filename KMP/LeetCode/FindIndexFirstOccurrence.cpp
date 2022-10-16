// 28. Find the Index of the First Occurrence in a String

class Solution {
public:
    vector<int> getLPS(string& str) {
        vector<int> lps(str.size());
        int i = 1, j = 0;
        
        while (i < str.size()) {
            if (str[i] == str[j]) {
                lps[i++] = ++j;
            } else {
                if (j != 0) {
                    j = lps[j-1];
                } else {
                    i++;
                }
            }
        }
        
        return lps;
    }
    
    int strStr(string haystack, string needle) {
        vector<int> lps = getLPS(needle);
        int i = 0, j = 0;
        
        while (i < haystack.length()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j != 0) {
                    j = lps[j-1];
                } else {
                    i++;
                }
            }
            
            if (j == needle.size()) {
                return i-needle.size();
            }
        }
        
        return -1;
    }
};