// 218. The Skyline Problem

class Solution {
public:
    const int start = 0, end = 1;
    vector<vector<int>> findPoints(vector<vector<int>>& lines) {
        priority_queue<int> pq;
        unordered_map<int, int> m;
        vector<vector<int>> points;

        pq.push(0);

        for (auto& line : lines) {
            int preHeight = pq.top();
            int height = line[1];
            if (line[2] == start) {
                pq.push(height);
                m[height]++;
            } else {
                m[height]--;
                while (pq.top() != 0 && m[pq.top()] == 0) {
                    pq.pop();
                }
            }

            if (preHeight != pq.top()) {
                if (line[2] == start) {
                    points.push_back({line[0], height});
                } else {
                    points.push_back({line[0], pq.top()});
                }
            }
        }

        return points;
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> lines;

        for (auto building: buildings) {
            lines.push_back({building[0], building[2], start});
            lines.push_back({building[1], building[2], end});
        } 

        sort(lines.begin(), lines.end(), [](vector<int>& a, vector<int>& b) -> bool {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            } else {
                if (a[2] && b[2]) {
                    return a[1] < b[1];
                } else if (a[2] != b[2]) {
                    return a[2] < b[2];
                } else {
                    return a[1] > b[1];
                }
            }
        });

        return findPoints(lines);
    }
};