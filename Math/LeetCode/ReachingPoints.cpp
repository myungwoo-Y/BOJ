// 780. Reaching Points

// Backward
class Solution {
public:
    unordered_map<int, unordered_set<int>> m;
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == sx && ty == sy) return true;
            if (tx > ty) {
                tx -= ty;
            } else {
                ty -= tx;
            }
        }
        return false;
    }
};

// Backward + Modulo
class Solution {
public:
    unordered_map<int, unordered_set<int>> m;
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == sx && ty == sy) return true;
            if (tx > ty) {
                if (ty > sy) {
                    tx %= ty;
                } else {
                    return (tx - sx) % ty == 0;
                }
            } else {
                if (tx > sx) {
                    ty %= tx;
                } else {
                    return (ty - sy) % tx == 0;
                }
            }
        }
        return false;
    }
};