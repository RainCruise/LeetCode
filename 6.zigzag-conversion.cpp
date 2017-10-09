//将字符串转化成正弦函数的形状，就能理解题意
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        int len = s.length();
        string *str = new string[numRows];
        int row = 0, step = 0;
        for (int i = 0; i < len; ++i) {
            str[row].push_back(s[i]);
            if (row == 0) {
                step = 1;
            } else if (row == numRows - 1) {
                step = -1;
            }
            row += step;
        }
        s.clear();
        for (int i = 0; i < numRows; ++i) {
            s.append(str[i]);
        }
        delete[] str;
        return s;
    }
};
