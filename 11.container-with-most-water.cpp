/*贪心法，假如A[0] < A[n - 1]，那么对于任意k(k < n - 1)，A[0]到A[k]能盛的水一定小于A[0]到A[n - 1]的盛水，
所以我们只要关注A[1]到A[n - 1]的最大盛水量就好了，综上，每次内移小的一方，同时跟踪记录最大值*／
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxArea = 0;
        while (left < right) {
            maxArea = fmax(maxArea, fmin(height[left], height[right])*(right - left));
            height[left] < height[right] ? left++ : right--;
        }
        return maxArea;
    }
};
