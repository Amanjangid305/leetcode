#include <string>
#include <queue>
#include <algorithm>

class Solution {
public:
    bool canReach(std::string s, int minJump, int maxJump) {
        int n = s.length();
        // If the destination itself is blocked, we can never reach it
        if (s[n - 1] == '1') return false;

        std::queue<int> q;
        q.push(0); // Start at index 0
        
        // 'far' keeps track of the maximum index we have ever added/considered
        int far = 0; 

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            // If we reached the last index, return true
            if (i == n - 1) return true;

            // Define the valid jump window boundaries from the current position 'i'
            int start = std::max(i + minJump, far + 1);
            int end = std::min(i + maxJump, n - 1);

            // Explore all valid positions within the window
            for (int j = start; j <= end; ++j) {
                if (s[j] == '0') {
                    q.push(j);
                }
            }

            // Update 'far' to the edge of the window we just processed
            far = std::max(far, i + maxJump);
        }

        return false;
    }
};