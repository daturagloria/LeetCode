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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p1 = dummy, *p2 = dummy;
        while (n--)
            p2 = p2->next;
        while (p2->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return dummy->next;
    }
};