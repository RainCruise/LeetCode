/*
If s[i] is '(', set longest[i] to 0,because any string end with '(' cannot be a valid one.

Else if s[i] is ')'

     If s[i-1] is '(', longest[i] = longest[i-2] + 2

     Else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() <= 1) return 0;
        int curMax = 0;
        vector<int> longest(s.size(), 0);
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    longest[i] = (i - 2 >= 0) ? (longest[i - 2] + 2) : 2;
                    curMax = max(longest[i], curMax);
                } else {
                    if (i - longest[i - 1] - 1 >= 0 && s[i-longest[i - 1] - 1] == '(') {
                    longest[i] = longest[i - 1] + 2 + ((i - longest[i - 1] - 2 >= 0) ? longest[i - longest[i - 1] - 2] : 0);
                    curMax = max(longest[i], curMax);
                    }
                }
            }
            //else if (s[i] == '(') , skip
        }
        return curMax;
    }
};
