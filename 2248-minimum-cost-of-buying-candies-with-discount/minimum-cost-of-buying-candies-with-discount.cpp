#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int minimumCost(std::vector<int>& cost) {
        // Sort the candies in descending order
        std::sort(cost.begin(), cost.end(), std::greater<int>());
        
        int total_cost = 0;
        
        for (int i = 0; i < cost.size(); ++i) {
            // Every 3rd item (at 0-indexed positions 2, 5, 8, etc.) is free.
            // We skip adding it to our total_cost.
            if ((i + 1) % 3 == 0) {
                continue; 
            }
            total_cost += cost[i];
        }
        
        return total_cost;
    }
};