// 480. Sliding Window Median

class Solution {
public:
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;
    unordered_map<int, int> m;
    unordered_map<int, int> deleteM;
    int maxSize = 0, minSize = 0;

    void updatePQ(int n) {
        if (maxSize == 0 || minSize == 0 || n < minQ.top()) {
            maxQ.push(n);
            maxSize++;
        } else {
            minQ.push(n);
            minSize++;
        }

        if (maxSize > minSize + 1) {
            minQ.push(maxQ.top());
            maxQ.pop();
            maxSize--;
            minSize++;
        } else if (minSize > maxSize) {
            maxQ.push(minQ.top());
            minQ.pop();
            maxSize++;
            minSize--;
        }
    }

    void deletePQ(int n) {
        deleteM[n]++;
        if (n < minQ.top()) {
            maxSize--;
        } else {
            minSize--;
        }

        // update min PQ
        while (minQ.size() && deleteM.find(minQ.top()) != deleteM.end()
            && deleteM[minQ.top()] > 0) {
                deleteM[minQ.top()]--;
                minQ.pop();
        }

        // update max PQ
        while (maxQ.size() && deleteM.find(maxQ.top()) != deleteM.end()
            && deleteM[maxQ.top()] > 0) {
                deleteM[maxQ.top()]--;
                maxQ.pop();
        }

        if (maxSize > minSize + 1) {
            minQ.push(maxQ.top());
            maxQ.pop();
            maxSize--;
            minSize++;
        } else if (minSize > maxSize) {
            maxQ.push(minQ.top());
            minQ.pop();
            maxSize++;
            minSize--;
        }

        // update min PQ
        while (minQ.size() && deleteM.find(minQ.top()) != deleteM.end()
            && deleteM[minQ.top()] > 0) {
                deleteM[minQ.top()]--;
                minQ.pop();
        }

        // update max PQ
        while (maxQ.size() && deleteM.find(maxQ.top()) != deleteM.end()
            && deleteM[maxQ.top()] > 0) {
                deleteM[maxQ.top()]--;
                maxQ.pop();
        }
    }

    double getSubAns() {
        double ret = 0;
        if ((maxSize + minSize) % 2 != 0) {
            ret = (double)maxQ.top();
        } else {
            ret = ((double)minQ.top() + maxQ.top()) / 2;
        }

        return ret;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ret;
        int l = 0, r = 0;

        while (r < k) {
            int n = nums[r];

            updatePQ(n);

            m[n]++;
            r++;
        }

        ret.push_back(getSubAns());

        while (r < nums.size()) {
            updatePQ(nums[r++]);
            deletePQ(nums[l++]);
            ret.push_back(getSubAns());
        }

        return ret;
    }
};