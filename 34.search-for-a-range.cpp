/*
    1. If A[mid] < target, then the range must begins on the right of mid (hence i = mid+1 for the next iteration)
    2. If A[mid] > target, it means the range must begins on the left of mid (j = mid-1)
    3. If A[mid] = target, then the range must begins on the left of or at mid (j= mid)

    1. If A[mid] > target, then the range must begins on the left of mid (j = mid-1)
    2. If A[mid] < target, then the range must begins on the right of mid (hence i = mid+1 for the next iteration)
    3. If A[mid] = target, then the range must begins on the right of or at mid (i= mid)
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        vector<int>result(2, -1);
        if (j == -1) return result;
        //Search for the left one
        while (i < j) {
            int mid = (i + j) / 2;
            if (nums[mid] < target) i = mid + 1;
            else j = mid;
        }
        if (nums[i] != target) return result;
        else result[0] = i;

        //Search for the right one;
        j = nums.size() - 1;
        while (i < j) {
            int mid = (i + j) / 2 + 1;
            if (nums[mid] > target) j = mid - 1;
            else i = mid;
        }
        result[1] = j;
        return result;
    }
};
