#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

// Utility function to find the k-th smallest element using Quickselect
int quickselect(vector<int>& nums, int left, int right, int k) {
    if (left == right) {
        return nums[left];
    }

    int pivot_index = left + rand() % (right - left + 1);
    int pivot_value = nums[pivot_index];
    swap(nums[pivot_index], nums[right]);

    int store_index = left;
    for (int i = left; i < right; ++i) {
        if (nums[i] < pivot_value) {
            swap(nums[store_index], nums[i]);
            store_index++;
        }
    }
    swap(nums[store_index], nums[right]);

    if (store_index == k) {
        return nums[store_index];
    } else if (store_index < k) {
        return quickselect(nums, store_index + 1, right, k);
    } else {
        return quickselect(nums, left, store_index - 1, k);
    }
}

// Function to find the k numbers closest to the median
	vector<int> findKClosestToMedian(vector<int>& nums, int k) {
    int n = nums.size();
    int median = quickselect(nums, 0, n - 1, n / 2);
    cout<<median<<" Median\n";

    // Calculate absolute differences from the median
    vector<int> diffs(n);
    for (int i = 0; i < n; ++i) {
        diffs[i] = abs(nums[i] - median);
    }

    // Use Quickselect to find the k smallest differences
    int kth_smallest_diff = quickselect(diffs, 0, n - 1, k - 1);

    // Collect the k closest numbers
    vector<int> result;
    for (int i = 0; i < n; ++i) {
        if (abs(nums[i] - median) <= kth_smallest_diff && result.size() < k) {
            result.push_back(nums[i]);
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 3, 3, 6, 7, 8, 9, 9, 9, 15};
    int k = 7;

    std::vector<int> closest = findKClosestToMedian(nums, k);

    std::cout << "The " << k << " numbers closest to the median are: ";
    for (int num : closest) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
