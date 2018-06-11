/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
  if (s.length < 2) return s;
  let minStart = 0, maxLen = 1;
  let curIndex = 0;
  while (curIndex < s.length) {
    if (s.length - curIndex < maxLen / 2) break;
    let j = k = curIndex;
    while (k < s.length - 1 && s[k+1] === s[k]) ++k;
    curIndex = k + 1;
    while (k < s.length - 1 && j > 0 && s[k+1] === s[j-1]) {
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
