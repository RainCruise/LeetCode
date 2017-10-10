class Solution {
public:
    int reverse(int x) {
        if (-10 < x && x < 10)
            return x;
        int sign = x < 0 ? -1 : 1;
        x = abs(x);
        long reverse_x = 0;
        while (x > 0) {
            reverse_x = reverse_x * 10 + x % 10;
            x /= 10;
        }
        return reverse_x > INT_MAX ? 0 : (int) (sign*reverse_x);
    }
};
