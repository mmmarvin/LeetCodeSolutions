/**
 * Possible solution to https://leetcode.com/problems/rotate-list
 * Marvin Manese
 **/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

template<class T>
T fast_positive_modulo(T input, T ceil)
{
    return input >= ceil ? input % ceil : input;
}

class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        ListNode* ret = NULL;

        if(head == NULL)
            return head;

        // First, get the size of the list
        int size_of_list = getSizeOfList(head);

        // Modulo the k to the size of the list
        // to get the number of rotations without
        // a full rotation
        int final_k = fast_positive_modulo(k, size_of_list);

        if(final_k == 0)
            return head;

        // Now we traverse the list, and change where
        // some of the elements point next
        // (size - kth) should point to NULL
        // Head should point to the (size + 1 - k)th element on the list
        // last element should always point to head
        ListNode* temporary_head = head;
        ListNode* current = head;
        int i = 0;
        while(i < size_of_list - final_k - 1 && current != NULL) {
            ++i;
            current = current->next;
        }

        // Create a pointer for the size - kth element
        ListNode* size_kth = current;

        while(current->next != NULL)
            current = current->next;

        // Create a pointer for the last element
        ListNode* tail = current;

        // Now, if size - kth isn't null
        if(size_kth != NULL) {
            // Now current = size - kth
            ListNode* temporary_next = size_kth->next;
            size_kth->next = NULL;

            // Now we need the head to point to the temporary_next
            ret = temporary_next;
            tail->next = temporary_head;

            return ret;
        }

        return head;
    }

private:
    int getSizeOfList(ListNode* head)
    {
        int i = 0;

        ListNode* temp = head;
        while(temp != NULL) {
            ++i;
            temp = temp->next;
        }

        return i;
    }
};
