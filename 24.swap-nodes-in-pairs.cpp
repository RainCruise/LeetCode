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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode **temp = &head, *pointer1 = NULL, *pointer2 = NULL;
        while ((pointer1 = *temp) && (pointer2 = pointer1->next)) {
            pointer1->next = pointer2->next;
            pointer2->next = pointer1;
            *temp = pointer2;
            temp = &(pointer1->next);
        }
        return head;
    }
};

//Pointer-pointer temp points to the pointer to the current node. So at first, temp points to head, and later it points to the next field of ListNodes. Additionally, for convenience and clarity, pointers a and b point to the current node and the next node.

//We need to go from *temp == a -> b -> (b->next) to *temp == b -> a -> (b->next). The first three lines inside the loop do that, setting those three pointers (from right to left). The fourth line moves temp to the next pair.
