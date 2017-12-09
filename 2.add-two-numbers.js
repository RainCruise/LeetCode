/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
  let carryNum = 0;
  let p = new ListNode(0);
  let q = p;
  while (l1 || l2) {
    let value = carryNum + (l1 ? l1.val : 0) + (l2 ? l2.val : 0);
    carryNum = Math.floor(value / 10); //注意js的除法并不自动取整
    value %= 10;
    p.next = new ListNode(value);
    p = p.next;
    if (l1) l1 = l1.next;
    if (l2) l2 = l2.next;
  }
  if (carryNum !== 0) p.next = new ListNode(carryNum);
  return q.next;
};
