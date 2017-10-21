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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    //并不删除节点，只是改变链接结构
       ListNode** pointer1 = &head, *pointer2 = head;
        for (int i = 1; i < n; ++i) {
            pointer2 = pointer2->next;
        }
        while (pointer2->next != NULL) {
            pointer1 = &((*pointer1)->next);
            pointer2 = pointer2->next;
        }
        *pointer1 = (*pointer1)->next;
        return head;
    }
};
