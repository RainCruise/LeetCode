class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();
        const vector<string> phone = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> result;
        result.push_back("");
        for (int i = 0; i < digits.size(); ++i) {
            int num = digits[i] - '0';
            if (num < 0 || 9 < num) break;
            const string candicate = phone[num];
            if (candicate.empty()) continue;
            vector<string> temp;
            for (int j = 0; j < candicate.size(); ++j) {
                for (int k = 0; k < result.size(); ++k) {
                    temp.push_back(result[k] + candicate[j]);
                }
            }
            result.swap(temp);
        }
        return result;
    }
};
