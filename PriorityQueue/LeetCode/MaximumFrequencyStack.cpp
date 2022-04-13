// 895. Maximum Frequency Stack

// O(logN)
struct  Element {
    int val, freq, pos;
};

struct cmp {
    bool operator()(const Element& x,const Element& y) const {
        if (x.freq == y.freq) {
            return x.pos > y.pos;
        } else {
            return x.freq > y.freq;
        }
    }
};


class FreqStack {
public:
    set<Element, cmp> s;
    unordered_map<int, int> cntMap;
    int pos = 0;

    FreqStack() {}
    
    void push(int val) {
        cntMap[val]++;

        Element e = {val ,cntMap[val], pos};
        s.insert(e);
        pos++;
    }
    
    int pop() {
        Element top = *s.begin();

        s.erase(s.begin());
        cntMap[top.val]--;

        return top.val; 
    }
};

// O(1)
class FreqStack {
public:
    unordered_map<int, int> freqMap;
    unordered_map<int, vector<int> > stackMap;
    int maxFreq = 0;

    FreqStack() {}
    
    void push(int val) {
        maxFreq = max(maxFreq, ++freqMap[val]);
        stackMap[freqMap[val]].push_back(val);
    }
    
    int pop() {
        int top = stackMap[maxFreq].back();

        freqMap[top]--;
        stackMap[maxFreq].pop_back();
        
        if (stackMap[maxFreq].size() == 0) {
            maxFreq -= 1;
        }

        return top;
    }
};