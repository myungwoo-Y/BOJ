// Title : Minimum Window Substring

// use sliding window
// index l and r respectively
// increase r first
// if all of charancter are in the window, increase l until meet a character in t

class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, chCnt = 0, cnt = 0;
        
        unordered_map<char, int> m;
        unordered_map<char, int> cntM;
        
        
        for (auto ch : t) {
            m[ch] = 0;
            chCnt += cntM[ch] == 0;
            cntM[ch]++;
        }
        
        pair<int, int> retRan;
        
        while(l <= r){
            
            // increase "l"
            if(cnt == chCnt){
                if((retRan.first == 0 && retRan.second == 0) ||r-l < retRan.second - retRan.first) retRan = {l, r};
                
                while(cnt >= chCnt){
                    char delCh = s[l];
                    l++;
                    if(m.find(delCh) != m.end()){
                        if(m[delCh] == cntM[delCh]) cnt--;
                        m[delCh]--;
                    }
                    if(cnt == chCnt && r-l < retRan.second - retRan.first){
                        retRan = {l, r};
                    }
                }
            }
            
            // increase "r"
            if(r < s.length()){
                char ch = s[r];
                
                bool isIn = m.find(ch) != m.end();
                
                if(isIn){
                    m[ch]++;
                    if(m[ch] == cntM[ch]) cnt++;
                }
                
                r++;
            }else{
                break;
            }
        }
        
        
        if (retRan.first == 0 && retRan.second == 0) return "";
        else return s.substr(retRan.first, retRan.second-retRan.first);
        
    }
};

// Optimized Sliding Window(better way than noraml sliding window)
class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> m;
        
        // think a length of t is total count which is threshold to update answer
        for(char ch : t){
            m[ch]++;
        }
        
        int remaining = t.length();
        
        vector<pair<char, int>> filtered;
        
        for (int i = 0; i < s.length(); i++) {
            if(m.find(s[i]) != m.end())
                filtered.push_back({s[i], i});
        }
        
        int minIdx = 0, minLen = numeric_limits<int>::max();
        
        int l = 0, r = 0;
        
        while(r < filtered.size()){
            if(--m[filtered[r++].first] >= 0) remaining--;
            
            while(remaining == 0){
                int newLen = filtered[r-1].second - filtered[l].second + 1;
                if(newLen <= minLen){
                    minIdx = filtered[l].second;
                    minLen = newLen;
                }
                
                if(++m[filtered[l++].first] > 0) remaining++;
            }
        }
        
        if(minLen == numeric_limits<int>::max()) return "";
        else return s.substr(minIdx, minLen);
    }
};