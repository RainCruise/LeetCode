/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
  if (s.length < 2) return s;
  let minStart = 0, maxLen = 1;
  let i = 0;
  while (i < s.length) {
    if (s.length - i < maxLen / 2) break;
    let j = k = i;
    while (k < s.length - 1 && s.charAt(k + 1) === s.charAt(k)) ++k;
    i = k + 1;
    while (k < s.length - 1 && j > 0 && s.charAt(k + 1) === s.charAt(j - 1)) {
      ++k;
      --j;
    }
    let newLen = k - j + 1;
    if (newLen > maxLen) {
      minStart = j;
      maxLen = newLen;
    }
  }
  return s.substr(minStart, maxLen);
};
