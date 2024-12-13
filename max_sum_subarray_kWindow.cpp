#include <iostream>
#include <vector>
#include <algorithm>

int maxSumSubarrayLengthK(const std::vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) {
        return -1;
    }

    // Calculate the sum of the first 'k' elements
    int max_sum = 0;
    for (int i = 0; i < k; ++i) {
        max_sum += nums[i];
    }

    int current_sum = max_sum;

    // Slide the window over the array, one element at a time
    for (int i = k; i < n; ++i) {
        current_sum += nums[i] - nums[i - k];
        max_sum = std::max(max_sum, current_sum);
    }

    return max_sum;
}

int main() {
    std::vector<int> nums = {1, 2, 3, -2, 5, -1, 2, 6, -3, 4};
    int k = 3;
    
    int result = maxSumSubarrayLengthK(nums, k);
    
    if (result != -1) {
        std::cout << "The maximum sum of a subarray of length " << k << " is: " << result << std::endl;
    }
    
    return 0;
}
