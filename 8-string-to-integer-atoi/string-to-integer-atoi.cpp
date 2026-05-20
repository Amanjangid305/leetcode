#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        long result = 0; // Using long to easily catch 32-bit overflow

        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check for sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // 3. Convert digits and prevent overflow
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            
            result = result * 10 + digit;

            // Check overflow limits dynamically
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return static_cast<int>(result * sign);
    }
};