// da3.hpp
// Author: Jewel Maldonado
// Last Edit Date: 2023-11-02
// Purpose: Header file containing function templates for Assignment 3

#ifndef DA3_HPP
#define DA3_HPP

#include <stdexcept>  // Includes standard exception classes like std::out_of_range
#include <cstddef>    // Includes definitions for size_t and other types
#include "llnode.hpp" // Includes the LLNode class template definition for linked list nodes
#include <functional> // Includes std::function to allow passing functions as arguments
#include <algorithm>  // Includes algorithms like std::is_sorted
#include <string>     // Includes std::string class and functions like std::to_string
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//

// Exercise A
// Function template to look up the nth element in a linked list
// Preconditions: The list must be null-terminated and index must be within the bounds of the list.
// Throws: std::out_of_range if the index is out of range.
template <typename ValueType>
ValueType lookup(const LLNode<ValueType>* head, std::size_t index) {
    const LLNode<ValueType>* current = head;
    std::size_t currentIndex = 0;

    // Traversal the linked list until the end or the specified index is reached
    while (current != nullptr) {
        if (currentIndex == index) {
            return current->_data; // Once found, return the data
        }
        current = current->_next;
        ++currentIndex;
    }

    // If the specified index is not found in the list, throw out-of-range exception
    throw std::out_of_range("Index " + std::to_string(index) + " is out of range for linked list lookup");
}

// Exercise B
// Function prototype for didItThrow
// This function calls another function and says whether it threw an exception.
void didItThrow(const std::function<void()>& ff, bool& threw);

// Exercise C
template <typename FDIter>
bool checkSorted(FDIter first, FDIter last) {
    return std::is_sorted(first, last);
}

// Excercise D
int gcd(int a, int b) ;

#endif // DA3_HPP
