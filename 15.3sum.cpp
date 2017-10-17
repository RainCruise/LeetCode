class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //输入非法检测
        if (nums.size() < 3) return {};
        vector<vector<int>> result;
        //对nums进行排序，满足题目中非降序排列的要求
        sort(nums.begin(), nums.end());

        //维护两个指针，寻找以nums[i]为第一位的解
        for (int i = 0; i < nums.size() - 2; ++i) {
            int p1 = i + 1, p2 = nums.size() - 1;
            while (p1 < p2) {
                vector<int> current;
                if (nums[i] + nums[p1] + nums[p2] == 0) {
                    current.push_back(nums[i]);
                    current.push_back(nums[p1]);
                    current.push_back(nums[p2]);
                    result.push_back(current);
                    ++p1;
                    --p2;
                    //注意要跳过重复的解
                    while (p1 < p2 && nums[p1 - 1] == nums[p1])
                        ++p1;
                    while (p1 < p2 && nums[p2 + 1] == nums[p2])
                        --p2;
                } else if (nums[i] + nums[p1] + nums[p2] < 0) {
                    ++p1;
                } else
                    --p2;
            }
            //这里也是跳过重复的解
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                ++i;
        }
        return result;
    }
};
