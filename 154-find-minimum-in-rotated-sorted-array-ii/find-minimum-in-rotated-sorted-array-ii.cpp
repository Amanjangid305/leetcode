class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // minimum is on right side
                left = mid + 1;
            }
            else if (nums[mid] < nums[right]) {
                // minimum is on left side
                right = mid;
            }
            else {
                // duplicate case
                right--;
            }
        }

        return nums[left];
    }
};