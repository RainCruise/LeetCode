//Basically, keep adding each integer to the sequence until the sum drops below 0. If sum is negative, then should reset the sequence.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            result = max(sum, result);
            sum = max(sum, 0);
        }
        return result;
    }
};
