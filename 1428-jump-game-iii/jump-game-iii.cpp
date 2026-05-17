#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (arr[i] == 0) return true;

            int right = i + arr[i];
            if (right < n && !visited[right]) {
                q.push(right);
                visited[right] = true;
            }

            int left = i - arr[i];
            if (left >= 0 && !visited[left]) {
                q.push(left);
                visited[left] = true;
            }
        }

        return false;
    }
};