class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res;
    }
};

/*
 *I can not tell where is the difference.
    if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
        return INT_MAX;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long long abs_dividend = labs(dividend), abs_divisor = abs(divisor);
    int result = 0;
    while (abs_dividend >= abs_divisor) {
        long long temp = abs_divisor, multiple = 1;
        while (abs_dividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        abs_dividend -= temp;
        result += multiple;
    }
    return sign == 1 ? result : -result;
    */

