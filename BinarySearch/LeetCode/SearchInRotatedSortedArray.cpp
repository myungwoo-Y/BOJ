// 33. Search in Rotated Sorted Array

class Solution {
public:
    int findPivotIdx(vector<int>& nums) {
        int ret = 0;
        int l = 0, r = nums.size()-1;

        while (l < r) {
            int p = (l + r) / 2;
            if (l == p) {
                p = p + 1;
            }
            if (nums[l] < nums[p]) {
                l = p;
            } else if (nums[p] < nums[r]) {
                r = p;
            } else {
                break;
            }
        }

        return l;
    }

    int getIdx(vector<int>& nums, int l, int r, int target) {
        if (l >= nums.size()) return -1;

        while (l <= r) {
            int p = (l + r) / 2;

            if (nums[p] == target) {
                return p;
            } else if (nums[p] < target) {
                l = p + 1;
            } else {
                r = p - 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int ans = -1;
        if (nums.size() == 1) {
            if (nums[0] == target) {
                return 0;
            } else {
                return -1;
            }
        } else {
            int pivot = findPivotIdx(nums);

            ans = max({ans, getIdx(nums, 0, pivot, target), getIdx(nums, pivot+1, nums.size()-1, target)});
        }

        return ans;
    }
};