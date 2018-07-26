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
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int x1 = l1 == nullptr ? 0 : l1->val;
            int x2 = l2 == nullptr ? 0 : l2->val;
            int sum = x1 + x2 + carry;
            carry = sum / 10;
            int n = sum % 10;
            p->next = new ListNode(n);
            p = p->next;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        if (carry > 0) {
            p->next = new ListNode(1);
        }
        return head->next;
    }
};