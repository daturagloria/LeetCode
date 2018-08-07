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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;
        else if (lists.size() == 1)
            return lists[0];
        else if (lists.size() == 2)
            return mergeTwoLists(lists[0], lists[1]);
        else
        {
            vector<ListNode *> list1, list2;
            for (int i = 0; i < lists.size() / 2; i++)
                list1.push_back(lists[i]);
            for (int i = lists.size() / 2; i < lists.size(); i++)
                list2.push_back(lists[i]);
            ListNode *p1 = mergeKLists(list1);
            ListNode *p2 = mergeKLists(list2);
            return mergeTwoLists(p1, p2);
        }
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        if (l1 != nullptr)
            p->next = l1;
        else
        {
            p->next = l2;
        }
        return head->next;
    }
};