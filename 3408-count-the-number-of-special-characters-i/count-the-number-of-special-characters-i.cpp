#include <string>
#include <unordered_set>

class Solution {
public:
    int numberOfSpecialChars(std::string word) {
        // Step 1: Store all unique characters present in the word
        std::unordered_set<char> charSet(word.begin(), word.end());
        
        int specialCount = 0;
        
        // Step 2: Check each alphabet letter from 'a' to 'z'
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            // Check if both lowercase and uppercase versions are in the set
            if (charSet.count(ch) && charSet.count(std::toupper(ch))) {
                specialCount++;
            }
        }
        
        return specialCount;
    }
};