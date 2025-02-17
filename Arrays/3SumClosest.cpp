#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool twoSum(vector<int>& arr, int s , int e, int target, int fixedNum, int &res) {
        while (s < e) {
            int sum = arr[s] + arr[e] + fixedNum;
            res = abs(res - target) > abs(sum - target) ? sum : res;
            if (sum > target) {
                e--;
            } else if (sum < target) {
                s++;
            } else {
                return true; // Exact match found, exit early
            }
        }
        return false;
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 3) {
            throw invalid_argument("Array must contain at least 3 elements.");
        }

        int res = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (twoSum(nums, i + 1, n - 1, target, nums[i], res)) {
                return target; // Early exit
            }
        }
        return res;
    }
};