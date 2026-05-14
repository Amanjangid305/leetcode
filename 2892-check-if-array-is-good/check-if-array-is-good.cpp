class Solution {
public:
    bool isGood(vector<int>& nums) {

        int n = *max_element(nums.begin(), nums.end());

        // Check size
        if (nums.size() != n + 1)
            return false;

        vector<int> freq(n + 1, 0);

        // Count frequency
        for (int num : nums) {
            if (num > n) return false;
            freq[num]++;
        }

        // Check 1 to n-1 appear once
        for (int i = 1; i < n; i++) {
            if (freq[i] != 1)
                return false;
        }

        // Check n appears twice
        if (freq[n] != 2)
            return false;

        return true;
    }
};