/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
  if (s.length <= 1) {
    return s.length;
  }
  let m = new Map();
  let start = -1;
  let maxLen = 0;
  for (let i = 0; i < s.length; ++i) {
    if (m.has(s.charAt(i))) {
      start = Math.max(start, m.get(s.charAt(i)));
    }
    m.set(s.charAt(i), i);
    maxLen = Math.max(maxLen, i - start);
  }
  return maxLen;
};
