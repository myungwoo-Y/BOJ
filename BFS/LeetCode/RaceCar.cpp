// 818. Race Car

struct Position {
    int position, speed, count;  
};

class Solution {
public:
    unordered_set<string> visited;
    
    string getKey(int position, int speed) {
        return to_string(position) + " " + to_string(speed);
    }
    
    int racecar(int target) {
        // f: position
        // s: speed
        queue<Position> q;
        visited.insert(getKey(0, 1));
        q.push({0, 1, 0});
        
        while (!q.empty()) {
            auto cur = q.front();
            int nextCnt = cur.count + 1;
            q.pop();
            
            if (cur.position == target) {
                return cur.count;
            }
            
            int nextSpeed = cur.speed * 2;
            int nextPos = cur.position + cur.speed;
            string key = getKey(nextPos, nextSpeed);
            if (visited.find(key) == visited.end() && nextPos > 0 && cur.position < (target << 1)) {
                q.push({cur.position+cur.speed, nextSpeed, nextCnt});                
                visited.insert(key);
            }
            
            int reverseSpeed = cur.speed > 0 ? -1 : 1;
            key = getKey(cur.position, reverseSpeed);
            if (visited.find(key) == visited.end()) {
                q.push({cur.position, reverseSpeed, nextCnt});    
                visited.insert(key);
            }
            
        }   
        
        return -1;
    }
};