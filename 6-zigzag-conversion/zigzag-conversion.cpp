class Solution {
public:
    string convert(string s, int numRows) {

        // Edge case
        if (numRows == 1 || s.length() <= numRows)
            return s;

        vector<string> rows(numRows);

        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {

            rows[currentRow] += c;

            // change direction at top or bottom
            if (currentRow == 0 || currentRow == numRows - 1)
                goingDown = !goingDown;

            // move
            if (goingDown)
                currentRow++;
            else
                currentRow--;
        }

        // combine rows
        string result;
        for (string row : rows)
            result += row;

        return result;
    }
};