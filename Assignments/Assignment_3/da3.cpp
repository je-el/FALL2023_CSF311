// da3.hpp
// Author: Jewel Maldonado
// Last Edit Date: 2023-11-02
// Purpose: Source file containing the implementation of da3.hpp
#include "da3.hpp"

//Exercise C
void didItThrow(const std::function<void()>& ff, bool& threw) {
    // assume no exception will be thrown
    threw = false;
    try {
        // Attempt to call the function
        ff();
    } catch (...) {
        // If an exception is caught, set threw to true and re-throw
        threw = true;
        throw; // Re-throw the current exception without handling it here
    }
}

// Exercise D - Recursive GCD
// Helper function for gcd that is hidden from the client code
// Not exposed in the header file, hence not callable by the client code
namespace {
    int gcdRecursive(int a, int b) {
        if (b == 0) return a;  // Base case: if b is 0, then a is the GCD
        return gcdRecursive(b, a % b);  // Recursive case: gcd(a, b) = gcd(b, a % b)
    }
}

// Public gcd function that client code will call
int gcd(int a, int b) {
    // Assuming a and b are nonnegative and not both zero.
    return gcdRecursive(a, b);
}
