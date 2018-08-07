/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *swapPairs(ListNode *linklist)
    {
        ListNode *head = new ListNode(0);
        head->next = linklist;
        ListNode *p = head;
        while (p->next)
        {
            ListNode *temp = p->next->next;
            if (!temp)
                return head->next;
            p->next->next = temp->next;
            temp->next = p->next;
            p->next = temp;
            p = temp->next;
        }
        return head->next;
    }
};