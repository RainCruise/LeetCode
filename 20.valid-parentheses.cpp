class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) return false;
        stack<char> parentheses;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case '(':
                    parentheses.push(s[i]);
                    break;
                case '{':
                    parentheses.push(s[i]);
                    break;
                case '[':
                    parentheses.push(s[i]);
                    break;
                case ']':
                    if (parentheses.empty() || parentheses.top() != '[')
                        return false;
                    parentheses.pop();
                    break;
                case '}':
                    if (parentheses.empty() || parentheses.top() != '{')
                        return false;
                    parentheses.pop();
                    break;
                case ')':
                    if (parentheses.empty() || parentheses.top() != '(')
                        return false;
                    parentheses.pop();
                    break;
                default: ;
            }
        }
        return parentheses.empty();
    }
};
