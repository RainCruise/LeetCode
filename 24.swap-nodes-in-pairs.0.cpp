/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Initial: preN | head | head->next|head->next->next
//After swap:preN | head->next | head | head->next->next

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *preN = dummy;
        while (head && head->next) {
            ListNode *nn = head->next->next;
            preN->next = head->next;
            head->next->next = head;
            head->next = nn;
            preN = head;
            head = nn;

        }
        return dummy->next;
    }
};
