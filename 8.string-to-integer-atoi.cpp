class Solution {
public:
    int myAtoi(string str) {
        int num = 0, sign = 1, i = str.find_first_not_of(' '), base = INT_MAX / 10;
        if (str[i] == '+' || str[i] == '-') sign = str[i++] == '+' ?: -1;
        while (isdigit(str[i])) {
            if (num > base || (num == base && str[i] - '0' > INT_MAX % 10))
                return sign > 0 ? INT_MAX : INT_MIN;
            num = 10 * num + (str[i++] - '0');
        }
        return sign * num;
    }
};
