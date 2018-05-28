/*题目描述： 翻转单链表
 * struct ListNode {
      ListNode* next;
 * }
 */

ListNode* reverseLinkedList(ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    ListNode *p, *q, *pr;
    p = head -> next;
    q = head;
    head -> next = NULL;
    while (p) {
        pr = p -> next;
        p -> next = q;
        q = p;
        p = pr;
    }
    return q;
}
