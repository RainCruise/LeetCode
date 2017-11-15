// BFS Problem !
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), step = 0, start = 0, end = 0;
        while (end < n - 1) {
            step++;
            int max_end = end + 1;
            for (int i = start; i <= end; ++i) {
                if (i + nums[i] > n - 2)
                    return step;
                max_end = max(max_end, i + nums[i]);
            }
            start = end + 1;
            end = max_end;
        }
        return step;
    }
};
