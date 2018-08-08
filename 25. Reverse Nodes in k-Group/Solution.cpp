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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr || k <= 1)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        while (head->next != nullptr)
            head = reverseNextK(head, k);
        return dummy->next;
    }

    ListNode *reverseNextK(ListNode *head, int k)
    {
        ListNode *p = head;
        for (int i = 0; i < k; i++)
        {
            if (p->next == nullptr)
                return p;
            p = p->next;
        }
        int count = 0;
        p = head->next->next;
        ListNode *tail = head->next;
        while (count++ < k - 1)
        {
            ListNode *temp = p->next;
            tail->next = temp;
            p->next = head->next;
            head->next = p;
            p = temp;
        }
        return tail;
    }
};