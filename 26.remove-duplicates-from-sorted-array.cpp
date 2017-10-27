class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int duplicates = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) duplicates++;
            else nums[i - duplicates] = nums[i];
        }
        //nums.erase(nums.end() - num_duplicates, nums.end()); //不需要删除向量末尾的元素，因为浪费时间
        return nums.size() - duplicates;
    }
};


/*
    for (int i = 1; i < nums.size(); ){
        if (nums[i] == nums[i - 1]) {
            nums.erase(nums.begin() + i);
            --i;
        }
        ++i;
    }
    return nums.size();

*/
