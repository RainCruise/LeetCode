//DFS
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(nums, result);
        return result;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &result) {
        if (nums.size() == 1) {
            vector<int> tmp(nums.begin(), nums.end());
            result.push_back(tmp);
            return;
        }
        vector<int> nums1(nums.begin() + 1, nums.end());
        dfs(nums1, result);
        vector<vector<int>> tmp_result;
        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j <= result[i].size(); ++j) {
                vector<int> tmp = result[i];
                tmp.insert(tmp.begin()+j, num[0]);
                tmp_result.push_back(tmp);
            }
        }
        result = tmp_result;
    }
};
