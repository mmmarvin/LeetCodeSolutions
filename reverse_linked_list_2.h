/**
 * Possible solution to https://leetcode.com/problems/reverse-linked-list-ii/
 * Marvin Manese
 **/

class Solution
{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        ListNode* curr = head;
        int i = 1;

        if(m > 1) {
            while(m - 1 > i) {
                curr = curr->next;
                ++i;
            }
            ListNode* left_end = curr;
            curr = curr->next;
            ListNode* middle_end = curr;
            ListNode* c = nullptr;
            while(n > i) {
                    ListNode* a = curr;
                    curr = curr->next;
                    a->next = c;
                    c = a;
                    ++i;
            }
            left_end->next = c;
            middle_end->next = curr;
        } else {
            ListNode* middle_end = curr;
            ListNode* c = nullptr;
            while(n >= i) {
                    ListNode* a = curr;
                    curr = curr->next;
                    a->next = c;
                    c = a;
                    ++i;
            }
            head = c;
            middle_end->next = curr;
        }

        return head;
    }
};
