class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b) {

        return (a[1] - a[0]) > (b[1] - b[0]);
    }

    int minimumEffort(vector<vector<int>>& tasks) {

        // Sort tasks
        sort(tasks.begin(), tasks.end(), cmp);

        int energy = 0;
        int current = 0;

        for (auto& task : tasks) {

            int actual = task[0];
            int minimum = task[1];

            // If current energy is less than required
            if (current < minimum) {

                energy += (minimum - current);

                current = minimum;
            }

            // Perform task
            current -= actual;
        }

        return energy;
    }
};