/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//遍历一次字符串，O(n)复杂度下可以解决。主要思路就是在遍历的过程中
//1. 记录每个字母上一次出现的位置
//2. 维持一个从当前位置往前数不包含重复字母的子串，记录这个字串的起止位置start, end
//根据相应位置字母是否出现过，以及上次出现的位置，不断更新start, end的过程。
        if (s.length() <= 1) {
            return s.length();
        }
        map<char, int> charMap;
        int start = -1, maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            if (charMap.count(s[i]) != 0) {
                start = max(start, charMap[s[i]]);
            }
            charMap[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
    }
};
