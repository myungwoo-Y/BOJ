// 895. Maximum Frequency Stack

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