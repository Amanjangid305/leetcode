#include <vector>
#include <set>
#include <algorithm>

class SegmentTree {
private:
    int n;
    std::vector<int> tree;

public:
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = std::max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        int left_query = query(2 * node, start, mid, l, r);
        int right_query = query(2 * node + 1, mid + 1, end, l, r);
        return std::max(left_query, right_query);
    }
};

class Solution {
public:
    std::vector<bool> getResults(std::vector<std::vector<int>>& queries) {
        // Find the maximum possible coordinate boundary needed
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = std::max(max_x, q[1]);
        }
        // Limit size according to problem constraints (max x is 50000)
        int M = std::max(max_x, 50005); 
        
        SegmentTree segTree(M);
        std::set<int> obstacles;
        
        // Sentinel obstacles to make neighbor searching seamless
        obstacles.insert(0);
        obstacles.insert(M);
        
        // Initially, the gap at coordinate M is the entire distance M - 0
        segTree.update(1, 0, M, M, M);
        
        std::vector<bool> results;
        
        for (const auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                int x = q[1];
                auto it = obstacles.upper_bound(x);
                int next_obs = *it;
                int prev_obs = *std::prev(it);
                
                obstacles.insert(x);
                
                // Update the gaps in the segment tree
                segTree.update(1, 0, M, x, x - prev_obs);
                segTree.update(1, 0, M, next_obs, next_obs - x);
                
            } else if (type == 2) {
                int x = q[1];
                int sz = q[2];
                
                // Find the closest obstacle to the left of or equal to x
                auto it = obstacles.upper_bound(x);
                int prev_obs = *std::prev(it);
                
                // 1. Max gap fully within obstacles up to prev_obs
                int max_gap = segTree.query(1, 0, M, 0, prev_obs);
                
                // 2. Trailing gap between prev_obs and x
                max_gap = std::max(max_gap, x - prev_obs);
                
                results.push_back(max_gap >= sz);
            }
        }
        
        return results;
    }
};