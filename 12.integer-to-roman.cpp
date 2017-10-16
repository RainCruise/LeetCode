class Solution {
public:
    string intToRoman(int num) {
        const string romanNums[] = {
            "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
            "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
            "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
            "", "M", "MM", "MMM", "MMMM" };
        return romanNums[num/1000 + 30] + romanNums[(num/100)%10 + 20] + romanNums[(num/10)%10 + 10] + romanNums[num%10];
    }
};
