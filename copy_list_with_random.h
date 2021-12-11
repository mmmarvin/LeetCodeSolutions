/**
 * Possible solution to https://leetcode.com/problems/copy-list-with-random-pointer/
 * Marvin Manese
 **/

#include <vector>
#include <unordered_map>

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution
{
public:
    RandomListNode* copyRandomList(RandomListNode* head)
    {
        struct RandomListNodePair
        {
            RandomListNodePair(RandomListNode* original_, RandomListNode* new_list_) : original(original_), new_list(new_list_) {}
            RandomListNode* original;
            RandomListNode* new_list;
        };

        typedef std::uintptr_t IntegerPointerType;
        typedef std::unordered_map<IntegerPointerType, RandomListNode*> ListNodeCollectionType;
        typedef std::vector<RandomListNodePair> ListNodePairArrayType;

        ListNodePairArrayType list_node_arr;              // List nodes to change the random
        ListNodeCollectionType list_node_collection;      // Collection of list nodes

        if(head == NULL)
            return NULL;

        // Create the new head
        RandomListNode* new_head = new RandomListNode(head->label);

        // Add the new list node to the collection
        list_node_collection.emplace(reinterpret_cast<IntegerPointerType>(head), new_head);

        // Add to list node array
        list_node_arr.emplace_back(head, new_head);

        // Move the pointers
        RandomListNode* new_current = new_head;
        RandomListNode* current = head->next;
        while(current != NULL) {
            new_current->next = new RandomListNode(current->label);
            new_current = advance_list_pointer(new_current);

            // Add it to the list node collection
            list_node_collection.emplace(reinterpret_cast<IntegerPointerType>(current), new_current);

            // First check if the random is NULL
            if(current->random == NULL) {
                new_current->random = NULL;
            } else {
                // Check if the current's random pointer is in the collection
                ListNodeCollectionType::iterator find_it = list_node_collection.find(reinterpret_cast<IntegerPointerType>(current->random));
                if(find_it != list_node_collection.end()) {
                    new_current->random = (*find_it).second;
                } else {
                    list_node_arr.emplace_back(current, new_current);
                }
            }

            // Move the current pointer
            current = advance_list_pointer(current);
        }

        // Now add the onces that aren't found
        for(ListNodePairArrayType::iterator it = list_node_arr.begin(), it_end = list_node_arr.end(); it != it_end; ++it) {
            RandomListNodePair& list_node_pair = (*it);

            ListNodeCollectionType::iterator find_it = list_node_collection.find(reinterpret_cast<IntegerPointerType>(list_node_pair.original->random));
            if(find_it != list_node_collection.end()) {
                list_node_pair.new_list->random = (*find_it).second;
            }
        }

        return new_head;
    }

private:
    RandomListNode* advance_list_pointer(RandomListNode* current)
    {
        current = current->next;
        return current;
    }
};
