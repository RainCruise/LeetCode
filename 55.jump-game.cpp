class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), i = 0;
        for (int maxJump = 0; i < n && i <= maxJump; ++i) {
            maxJump = max(maxJump, nums[i] + i);
        }
        return i == n;
    }
};
