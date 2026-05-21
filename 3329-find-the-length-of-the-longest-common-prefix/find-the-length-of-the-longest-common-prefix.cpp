#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

class Solution {
public:
    int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::unordered_set<int> prefixes;

        // Step 1: Insert all possible prefixes of numbers in arr1 into the Hash Set
        for (int val : arr1) {
            while (val > 0) {
                prefixes.insert(val);
                val /= 10; // Chops off the last digit to get the next prefix
            }
        }

        int maxLength = 0;

        // Step 2: Check prefixes of numbers in arr2 against the Hash Set
        for (int val : arr2) {
            while (val > 0) {
                // If this prefix exists in arr1's set
                if (prefixes.count(val)) {
                    // Calculate digit length of the matching prefix
                    int currentLength = std::to_string(val).length();
                    maxLength = std::max(maxLength, currentLength);
                    
                    // Optimization: Once we find a match for a number, smaller prefixes 
                    // of this same number won't beat our current maxLength, so we can break.
                    break; 
                }
                val /= 10;
            }
        }

        return maxLength;
    }
};