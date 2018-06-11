/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
  const INT_MAX = 2147483647, INT_MIN = -2147483648;
  let result = parseInt(str);
  return isNaN(result) ? INT_MAX : result;
};
