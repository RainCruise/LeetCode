class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<bool> cols(n, true);
        vector<bool> main(2 * n - 1, true);
        vector<bool> anti(2 * n - 1, true);
        solve(0, n, result, cols, main, anti);
        return result;
    }
private:
    void solve(int s, int &n, int count, vector<bool> &cols, vector<bool> &main, vector<bool> &anti) {
        if (s == n) {
            count++;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (cols[i] && main[s + i] && anti[s + cols.size() - 1 - i])
            {
                cols[i] = main[s + i] = anti[s + cols.size() - 1 - i] = false;
                solve(s + 1, n, count, cols, main, anti);
                cols[i] = main[s + i] = anti[s + cols.size() - 1 - i] = true;
            }
          }
        }
    }
};
