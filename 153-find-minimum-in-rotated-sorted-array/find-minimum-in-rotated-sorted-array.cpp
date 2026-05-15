class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            // Case 1: mid is greater → min is on right
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // Case 2: mid is smaller → min is on left
            else {
                right = mid;
            }
        }

        return nums[left];
    }
};