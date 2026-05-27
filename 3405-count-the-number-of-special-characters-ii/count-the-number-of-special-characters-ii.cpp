#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int numberOfSpecialChars(std::string word) {
        // Arrays to store the last position of lowercase and first position of uppercase characters.
        // Initialized to -1 to represent that the character hasn't been seen yet.
        std::vector<int> last_lower(26, -1);
        std::vector<int> first_upper(26, -1);
        
        // Array to flag if a character is disqualified (e.g., lower appears after an upper)
        std::vector<bool> invalid(26, false);

        for (int i = 0; i < word.length(); ++i) {
            char ch = word[i];
            
            if (std::islower(ch)) {
                int idx = ch - 'a';
                last_lower[idx] = i;
                
                // If we encounter a lowercase character AFTER we've already seen 
                // its uppercase version, this letter is completely disqualified.
                if (first_upper[idx] != -1) {
                    invalid[idx] = true;
                }
            } else {
                int idx = ch - 'A';
                // Record the index only if it's the FIRST time seeing this uppercase letter
                if (first_upper[idx] == -1) {
                    first_upper[idx] = i;
                }
            }
        }

        int special_count = 0;

        // Verify conditions for all 26 letters
        for (int i = 0; i < 26; ++i) {
            // A character is special if:
            // 1. It is not marked invalid.
            // 2. We saw both its lowercase and uppercase forms.
            // 3. The last lowercase index is strictly smaller than the first uppercase index.
            if (!invalid[i] && last_lower[i] != -1 && first_upper[i] != -1 && last_lower[i] < first_upper[i]) {
                special_count++;
            }
        }

        return special_count;
    }
};