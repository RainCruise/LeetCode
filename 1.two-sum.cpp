/* 2Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //采用hashMap，能在o(1)的时间完成查找
        vector<int> result;
        if(nums.size() <= 1) return result;  //边界情况
        //新建一个map<key,value> 模式的来存储numbers里面的元素和index，
        unordered_map<int, int> myMap;
        for(int i = 0; i < nums.size(); ++i) {
            myMap[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); ++i) {
            int result_value = target - nums[i];
            if(myMap.find(result_value) != myMap.end()) {
                int index = myMap[result_value];
                if(index == i) continue;
                if(index < i) {
                    result.push_back(index);
                    result.push_back(i);
                    return result;
                }
                else {
                    result.push_back(i);
                    result.push_back(index);
                    return result;
                }
            }
        }
    }
};
