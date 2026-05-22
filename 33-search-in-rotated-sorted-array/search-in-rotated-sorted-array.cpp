#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If the target is found, return its index
            if (nums[mid] == target) {
                return mid;
            }
            
            // Case 1: Check if the left side is strictly sorted
            if (nums[left] <= nums[mid]) {
                // Check if the target lies within the boundaries of the sorted left half
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Narrow search to the left half
                } else {
                    left = mid + 1;  // Narrow search to the right half
                }
            } 
            // Case 2: Otherwise, the right side must be strictly sorted
            else {
                // Check if the target lies within the boundaries of the sorted right half
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // Narrow search to the right half
                } else {
                    right = mid - 1; // Narrow search to the left half
                }
            }
        }
        
        // Return -1 if the target is not present in the array
        return -1;
    }
};