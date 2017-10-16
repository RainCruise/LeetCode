class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string str1 = strs[0];
        if (str1 == "") return "";
        for (int i = 1; i < strs.size(); ++i) {
            string str2 = strs[i];
            if (str2 == "") return "";

            int index = 0;
            while (str1[index] == str2[index]) ++index;
            str1 = str2.substr(0, index);
        }
        return str1;
    }
};
