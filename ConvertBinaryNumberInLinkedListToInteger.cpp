/**
 * Solution to https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
 **/
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
    int getDecimalValue(ListNode* head) {
        int ret = 0;
        
        auto* curr = head;
        if(curr->val == 1)
            ret |= 0x1;
        curr = curr->next;
        while(curr) {
            ret = ret << 1;
            if(curr->val == 1)
                ret |= 0x1;
            curr = curr->next;
        }
                
        return ret;
    }
};
