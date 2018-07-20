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
    const xString = x.toString();
    const xStringReverse = xString.split('').reverse().join('');
    return xString === xStringReverse;
};
