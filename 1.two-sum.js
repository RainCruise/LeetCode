/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  let m = new Map();
  for (let i = 0; i < nums.length; ++i) {
    m.set(nums[i], i);
  }
  for (let i = 0; i < nums.length; ++i) {
    let temp = target - nums[i];
    if (m.get(temp)) {
      return [i, m.get(temp)];
    }
  }
};
