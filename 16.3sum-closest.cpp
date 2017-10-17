class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int minDistance = INT_MAX;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int p1 = i + 1;
            int p2 = nums.size() - 1;
            while (p1 < p2) {
                int tempSum = nums[i] + nums[p1] + nums[p2];
                int tempDistance = 0;
                if (tempSum < target) {
                    tempDistance = target - tempSum;
                    if (tempDistance < minDistance) {
                        minDistance = tempDistance;
                        result = tempSum;
                    }
                    ++p1;
                } else if (tempSum > target) {
                    tempDistance = tempSum - target;
                    if (tempDistance < minDistance) {
                        minDistance = tempDistance;
                        result = tempSum;
                    }
                    --p2;
                } else {
                    result = nums[i] + nums[p1] + nums[p2];
                    return result;
                }
            }
        }
        return result;
    }
};
