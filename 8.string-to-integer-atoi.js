/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
  const INT_MAX = 2147483647, INT_MIN = -2147483648;
  let result = isNaN(parseInt(str)) ? 0 : parseInt(str);
  if (result < INT_MIN) result = INT_MIN;
  if (result > INT_MAX) result = INT_MAX;
  return result;
};
