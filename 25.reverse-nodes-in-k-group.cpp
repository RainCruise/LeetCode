/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    -1 -> 1 -> 2 -> 3 -> 4 -> 5
     |    |    |    |
    pre  cur  nex  tmp

    -1 -> 2 -> 1 -> 3 -> 4 -> 5
     |         |    |    |
    pre       cur  nex  tmp

    -1 -> 3 -> 2 -> 1 -> 4 -> 5
     |              |    |    |
    pre            cur  nex  tmp
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;
        int num = 0;   //number of ListNodes
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy, *nex, *tmp, *pre = dummy;
        while (cur = cur->next) num++;
        while (num >= k) {
            cur = pre->next;
            nex = cur->next;
            for (int i = 1; i < k; ++i) {
                tmp = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                cur->next = tmp;
                nex = tmp;
            }
            pre = cur;
            num -= k;
        }
        return dummy->next;
    }
};
