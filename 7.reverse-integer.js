/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
  if ( -10 < x && x < 10) return x;
  const sign = x > 0 ? 1 : -1;
  x = Math.abs(x);
  let stringX = String(x);
  let reverseX = parseInt(stringX.split('').reverse().join(''));
  return reverseX > 2 ** 31 - 1 ? 0 : reverseX* sign;
};
