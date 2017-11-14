class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); ++i) {
            myMap[nums[i]] = i;
        }
        int positive = 1;
        while (true) {
            if (myMap.find(positive) != myMap.end()) {
                ++positive;
                continue;
            }
            return positive;
        }
    }
};
