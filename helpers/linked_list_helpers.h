/**
 * Linked list helpers for typical linked list problems
 * in LeetCode
 */

#ifndef GUARD_linked_list_helpers_H
#define GUARD_linked_list_helpers_H

#include <iostream>

namespace detail
{
    template<class L> void do_nothing(L*) {}
}

template<class L>
L* advance_list_pointer(L* current)
{
    current = current->next;
    return current;
}

template<class L, class F>
L* create_dummy_list(std::size_t number,
#if __cplusplus >= 201103L
    F&& additional_thing_to_do)
#else
    F& additional_thing_to_do)
#endif // __cplusplus >= 201103L
{
    if(number == 0)
        return NULL;

    L* ret = new L(0);
    L* current = ret;
    for(std::size_t i = 1; i < number; ++i) {
        int i_in_int = static_cast<int>(i);
        current->next = new L(i_in_int);
        current = advance_list_pointer(current);
#if __cplusplus >= 201103L
        std::forward<F>(additional_thing_to_do)(current);
#else
        additional_thing_to_do(current);
#endif // __cplusplus >= 201103L
    }
    current->next = NULL;

    return ret;
}

template<class L>
L* create_dummy_list(std::size_t number)
{
    return create_dummy_list<L>(number, detail::do_nothing<L>);
}

template<class L>
void print_list(L* head, int (L::*val) = &L::value)
{
    L* current = head;
    std::cout << "List content: [";
    while(current != NULL) {
        std::cout << current->*val;
        current = advance_list_pointer(current);
        if(current != NULL)
             std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

template<class L>
void destroy_list(L* head)
{
    L* current = head;
    while(current != NULL) {
        L* temp = current;
        current = advance_list_pointer(current);
        delete temp;
    }
}

#endif // GUARD_linked_list_helpers_H
