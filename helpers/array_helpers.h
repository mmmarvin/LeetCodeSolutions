#ifndef GUARD_array_helpers_H
#define GUARD_array_helpers_H

#include <iostream>
#include <vector>

template<class T>
void print_array(std::vector<T>& arr)
{
    std::cout << "Array: [";
    for(typename std::vector<T>::const_iterator it = arr.begin(), it_end = arr.end(); it != it_end; ++it){
        std::cout << (*it);
        if(it + 1 != it_end)
            std::cout << ",";
    }
    std::cout << "]" << std::endl;
}

template<class T>
void push_numbers(std::vector<T>& arr, T val)
{
    arr.clear();
    for(int i = 0, i_end = static_cast<int>(val); i < i_end; ++i)
        arr.push_back(i);
}

#endif // GUARD_array_helpers_H
