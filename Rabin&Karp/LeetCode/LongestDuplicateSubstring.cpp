// 1044. Longest Duplicate Substring

class Solution {
public:
    long mod = 1000000007;
    string searchLongest(string& s) {
        int l = 1, r = s.length();
        
        while (l <= r) {
            int mid = l + (r - l) / 2;

            int startIdx = getStartIdxOfDuplicatedStr(s, mid);

            if (startIdx != -1) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        int targetIdx = getStartIdxOfDuplicatedStr(s, l-1);
        
        if (targetIdx == -1) {
            return "";
        } else {
            return s.substr(targetIdx, l-1);
        }
    }

    int getStartIdxOfDuplicatedStr(string& s, int length) {
        if (length == 0) return -1;
        
        unordered_map<long, vector<int>> hashMap;

        long hash = 0, k = 26, p = 1;

        for (int i = length-1; i >= 0; i--) {
            hash += (long)(s[i] - 'a') * p;
            hash %= mod;
            
            if (i != 0) {
                p = (p * k) % mod;                
            }
        }

        hashMap[hash] = vector<int>();
        hashMap[hash].push_back(0);
        
    
        for (int i = length; i < s.length(); i++) {
            hash = ((((hash - (s[i-length] - 'a') * p % mod )) * k) % mod + mod) % mod + (s[i]-'a');
            hash %= mod;
            if (hashMap.find(hash) != hashMap.end()) {
                vector<int>& starts = hashMap[hash];
                int targetStart = i-length+1;
                string target = s.substr(targetStart, length);
                for (auto start : starts) {
                    if (s.substr(start, length) == target) {
                        return targetStart;
                    }
                }
            } else {
                hashMap[hash] = vector<int>();
            }
            hashMap[hash].push_back(i-length+1);
        }

        return -1;
    }

    string longestDupSubstring(string s) {
        string ret = searchLongest(s);

        return ret;
    }
};
