/*************************************************************************
    @ File Name: 9.palindrome-number.js
    @ Author: Rain
    @ Mail: yutiangan@yangqianguan.com
    @ Created Time: 六  7/14 17:34:53 2018
 ************************************************************************/

/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    let xString = x.toString();
    let headPointer = 0, tailPointer = xString.length - 1;
    while (headPointer < tailPointer) {
        if (xString[headPointer] !== xString[tailPointer]) return false;
        headPointer ++;
        tailPointer --;
    }
    return true;
};
