class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int num_removed = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) ++num_removed;
            else if (num_removed != 0) nums[i - num_removed] = nums[i];
            //不用下面这一行因为在num_removed = 0 的时候复制了多次,浪费时间
            //else nums[i - num_removed] = nums[i];
        }
        return nums.size() - num_removed;
    }
};
