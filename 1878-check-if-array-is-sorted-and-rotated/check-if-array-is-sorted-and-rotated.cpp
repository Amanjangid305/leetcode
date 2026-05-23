#include <vector>

class Solution {
public:
    bool check(std::vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            // Check if current element is greater than the next element
            // (i + 1) % n handles the wrap-around from last element to the first
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            
            // If there is more than 1 drop, it cannot be a sorted rotated array
            if (count > 1) {
                return false;
            }
        }
        
        return true;
    }
};