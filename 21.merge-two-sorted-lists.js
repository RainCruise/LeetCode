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
var mergeTwoLists = function(l1, l2) {
    let dumpy = new ListNode(-1);
    let p = dumpy;
    while (l1 && l2) {
        if (l1.val < l2.val) {
            p.next = new ListNode(l1.val);
            p = p.next;
            l1 = l1.next;
        } else {
            p.next = new ListNode(l2.val);
            p = p.next;
            l2 = l2.next;
        }
    }
    if (l1) {
        p.next = l1;
    } else {
        p.next = l2;
    }
    return dumpy.next;
};
