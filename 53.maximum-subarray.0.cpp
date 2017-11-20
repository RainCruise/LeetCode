//maxSubArray(A, i) = maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1) : 0 + A[i];
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxSubArray(n);
        maxSubArray[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxSubArray[i] = nums[i] + (maxSubArray[i - 1] > 0 ? maxSubArray[i - 1] : 0);
            result = max(result, maxSubArray[i]);
        }
        return result;
    }
};
