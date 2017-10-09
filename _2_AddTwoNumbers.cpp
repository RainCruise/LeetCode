/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //思路很简单，直接相加就行，考虑进位
        ListNode temp(0);
        ListNode* p = &temp;
        int carryNum = 0;

        while(l1 || l2) {
            int value = carryNum + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carryNum = value / 10;
            value %= 10;
            p->next = new ListNode(value);
            p = p->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carryNum != 0) p->next = new ListNode(carryNum);
        return temp.next;
    }
};
