//Jewel Maldonado
//CS311
//2023-09-25
//da3.hpp

#ifndef DA3_HPP
#define DA3_HPP

#include <functional>
using std::function;
#include <stdexcept>
#include "llnode.hpp"

// Exercise A - Linked List Lookup
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head, std::size_t index);

// Exercise B - Did It Throw?
void didItThrow(const function<void()> & ff, bool & threw);

// Exercise C - Check Sorted
template <typename FDIter>
bool checkSorted(FDIter first, FDIter last);

// Exercise D - Recursive GCD
int gcd(int a, int b);

#endif  // DA3_HPP
