//Jewel Maldonado
//CS311
//2023-09-25
//da3.cpp

#include "da3.hpp"
#include <functional>
using std::function;
#include <stdexcept>
#include <algorithm>
#include "llnode.hpp"


// Exercise A - Linked List Lookup
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head, std::size_t index) {
    while (head != nullptr && index > 0) {
        head = head->next;
        index--;
    }

    if (head == nullptr) {
        throw std::out_of_range("Index out of range.");
    }
    return head->data;
}

// Exercise B - Did It Throw?
void didItThrow(const function<void()> & ff, bool & threw)
{
  threw=false;
  try{
    ff();
  }
   catch(...)
  { 
    threw = true;
    throw;
    }
 }

// Exercise C - Check Sorted
template <typename FDIter>
bool checkSorted(FDIter first, FDIter last) {
    return std::is_sorted(first, last);
}

// Exercise D - Recursive GCD
int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    return gcd(b, a % b);
}
