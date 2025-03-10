
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int max_sum = nums[0]; // Initialize with first element
    int current_sum = nums[0];

    for (size_t i = 1; i < nums.size(); i++) {
        current_sum = max(nums[i], current_sum + nums[i]); // Start fresh or continue
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}