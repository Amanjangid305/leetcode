class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();

        vector<int> freq(n + 1, 0);
        vector<int> ans;

        int common = 0;

        for (int i = 0; i < n; i++) {

            // Add element from A
            freq[A[i]]++;

            // If frequency becomes 2,
            // it means element is present in both prefixes
            if (freq[A[i]] == 2)
                common++;

            // Add element from B
            freq[B[i]]++;

            // Check again
            if (freq[B[i]] == 2)
                common++;

            // Store answer for current index
            ans.push_back(common);
        }

        return ans;
    }
};