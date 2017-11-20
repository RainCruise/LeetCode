class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        if (m == 0) return result;
        int n = matrix[0].size();
        if (n == 0) return result;
        char direction = 'r'; //direction
        int l = 0, r = n - 1, u = 1, d = m - 1; //limit of 4 directions
        int i = 0, j = -1;
        for (int k = 0; k < m * n; ++k) {
            if (direction == 'r') {
                j++;
                if (j == r) {
                    r--;
                    direction = 'd';
                }
            } else if (direction == 'd') {
                i++;
                if (i == d) {
                    d--;
                    direction = 'l';
                }
            } else if (direction == 'l') {
                j--;
                if (j == l) {
                    l++;
                    direction = 'u';
                }
            } else if (direction == 'u') {
                i--;
                if (i == u) {
                    u++;
                    direction = 'r';
                }
            }
            result.push_back(matrix[i][j]);
        }
        return result;
    }
};
