class Solution {
public:
    bool isPalindrome(int x) {
        // Base cases: negative numbers and numbers ending in 0 (except 0 itself)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        
        // Keep reversing until we reach the middle of the number
        while (x > reversedHalf) {
            int lastDigit = x % 10;
            reversedHalf = (reversedHalf * 10) + lastDigit;
            x /= 10;
        }

        // For even-length numbers: x == reversedHalf
        // For odd-length numbers: x == reversedHalf / 10 (gets rid of the middle digit)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};