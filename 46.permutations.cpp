//Recrursive Solution
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteRecursive(nums, result, 0);
        return result;
    }

    void permuteRecursive(vector<int> &nums, vector<vector<int>> &result, int begin) {
        if (begin >= nums.size()) {
            // one permutation instance
            result.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); ++i) {
            swap(nums[begin], nums[i]);
            permuteRecursive(nums, result, begin + 1);
            //reset
            swap(nums[begin], nums[i]);
        }
    }

};
