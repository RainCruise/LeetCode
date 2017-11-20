class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int> > directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> result;
        int m = matrix.size();    if (m == 0) return result;
        int n = matrix[0].size(); if (n == 0) return result;

        vector<int> nSteps{n, m - 1};
        int dir = 0;
        int ir = 0, ic = -1;
        while (nSteps[dir%2]) {
            for (int i = 0; i < nSteps[dir%2]; i++) {
                ir += directions[dir][0];
                ic += directions[dir][1];
                result.push_back(matrix[ir][ic]);
            }
            nSteps[dir%2]--;
            dir = (dir + 1) % 4;
        }
        return result;
    }
};
