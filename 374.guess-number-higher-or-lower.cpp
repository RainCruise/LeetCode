/*
 * We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.
Return 6.
*/
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int maxNum = n, minNum = 1;
        while (true) {
            int meanNum = (maxNum - minNum) / 2 + minNum; //if use (maxNum + minNum) >> 1, it coule overflow.
            int res = guess(meanNum);
            if (res == 0) {
                return meanNum;
            } else if (res == 1) {
                minNum = meanNum + 1;
            } else {
                maxNum = meanNum - 1;
            }
        }
    }
};
