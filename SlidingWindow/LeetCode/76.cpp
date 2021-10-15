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