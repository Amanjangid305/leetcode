#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {
            vector<int> elems;

            // Extract layer
            for (int j = layer; j < n - layer; j++) // top row
                elems.push_back(grid[layer][j]);
            for (int i = layer + 1; i < m - layer; i++) // right col
                elems.push_back(grid[i][n - layer - 1]);
            for (int j = n - layer - 2; j >= layer; j--) // bottom row
                elems.push_back(grid[m - layer - 1][j]);
            for (int i = m - layer - 2; i > layer; i--) // left col
                elems.push_back(grid[i][layer]);

            int L = elems.size();
            int k_mod = k % L;

            // Rotate
            vector<int> rotated(L);
            for (int i = 0; i < L; i++) {
                rotated[i] = elems[(i + k_mod) % L];
            }

            // Put back rotated layer
            int idx = 0;
            for (int j = layer; j < n - layer; j++)
                grid[layer][j] = rotated[idx++];
            for (int i = layer + 1; i < m - layer; i++)
                grid[i][n - layer - 1] = rotated[idx++];
            for (int j = n - layer - 2; j >= layer; j--)
                grid[m - layer - 1][j] = rotated[idx++];
            for (int i = m - layer - 2; i > layer; i--)
                grid[i][layer] = rotated[idx++];
        }

        return grid;
    }
};
