class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int pointer1 = i + 1; pointer1 < nums.size() - 2; ++pointer1) {
                if (pointer1 > i + 1 && nums[pointer1] == nums[pointer1 - 1]) continue;
                int pointer2 = pointer1 + 1;
                int pointer3 = nums.size() - 1;
                while (pointer2 < pointer3) {
                    int sum = nums[i] + nums[pointer1] + nums[pointer2] + nums[pointer3];
                    if (sum == target) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[pointer1]);
                        temp.push_back(nums[pointer2]);
                        temp.push_back(nums[pointer3]);
                        result.push_back(temp);
                        do {
                            ++pointer2;
                        } while (pointer2 < pointer3 && nums[pointer2] == nums[pointer2 - 1]);
                        do {
                            --pointer3;
                        } while (pointer2 < pointer3 && nums[pointer3] == nums[pointer3 + 1]);
                    } else if (sum < target) {
                        ++pointer2;
                    } else {
                        --pointer3;
                    }
                }
            }
        }
        return result;
    }
};
