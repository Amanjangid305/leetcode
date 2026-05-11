class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> merged;

        // Put nums1 elements
        for (int num : nums1) {
            merged.push_back(num);
        }

        // Put nums2 elements
        for (int num : nums2) {
            merged.push_back(num);
        }

        // Sort final array
        sort(merged.begin(), merged.end());

        int n = merged.size();

        // Odd length
        if (n % 2 == 1) {
            return merged[n / 2];
        }

        // Even length
        else {
            return (merged[n/2] + merged[(n/2)-1]) / 2.0;
        }
    }
};