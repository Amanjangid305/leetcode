#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.length();
        int n = p.length();
        
        // dp[i][j] stores if s[0...i-1] matches p[0...j-1]
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        
        // Base case: Empty string matches empty pattern
        dp[0][0] = true;
        
        // Base case: Deal with patterns like a*, a*b*, a*b*c* matching an empty string s
        for (int j = 2; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                
                // Case 1: Pattern character is a literal or '.'
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                // Case 2: Pattern character is '*'
                else if (p[j - 1] == '*') {
                    // Subcase 2a: Match 0 times (skip the character and the '*')
                    dp[i][j] = dp[i][j - 2];
                    
                    // Subcase 2b: Match 1 or more times (if preceding character matches)
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};