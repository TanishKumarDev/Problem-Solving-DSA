#include <bits/stdc++.h>
using namespace std;

int main() {
    // Test cases with different integer types
    int n = 23; // Binary: 10111
    long l = 12345L; // Binary: 11000000111001
    long long ll = 123456789LL; // Binary: 111010110111100110100010101

    // Using __builtin_popcount for int
    cout << "Number: " << n << " (Binary: 10111)\n";
    cout << "Popcount: " << __builtin_popcount(n) << "\n"; // Output: 5

    // Using __builtin_popcountl for long
    cout << "\nNumber: " << l << " (Binary: 11000000111001)\n";
    cout << "Popcount: " << __builtin_popcountl(l) << "\n"; // Output: 6

    // Using __builtin_popcountll for long long
    cout << "\nNumber: " << ll << " (Binary: 111010110111100110100010101)\n";
    cout << "Popcount: " << __builtin_popcountll(ll) << "\n"; // Output: 16

    // Use case: Count set bits in an array
    vector<int> arr = {7, 12, 23, 0, 31}; // Binary: 111, 1100, 10111, 0, 11111
    cout << "\nSet bits in array:\n";
    for (int x : arr) {
        cout << "Number: " << x << ", Set bits: " << __builtin_popcount(x) << "\n";
    } // Output: 
    // Number: 7, Set bits: 3
    // Number: 12, Set bits: 3
    // Number: 23, Set bits: 5
    // Number: 0, Set bits: 0
    // Number: 31, Set bits: 5

    // Use case: Check if number is power of 2 (has exactly one set bit)
    int power_of_2 = 16; // Binary: 10000
    cout << "\nNumber: " << power_of_2 << " (Binary: 10000)\n";
    cout << ( __builtin_popcount(power_of_2) == 1 ? "Is power of 2" : "Not power of 2") << "\n"; // Output: Is power of 2

    return 0;
}

/*
# GCC __builtin_popcount Overview
- __builtin_popcount, which is not part of the C++ STL but is a GCC built-in function commonly used in competitive programming.
- Purpose: Counts the number of 1s (set bits) in the binary representation of an unsigned integer.
- Implementation: Built-in GCC function, optimized at the hardware level (e.g., using CPU instructions like POPCNT).

Properties:
- Variants: __builtin_popcount (for int), __builtin_popcountl (for long), __builtin_popcountll (for long long).
- Input must be unsigned (behavior undefined for negative numbers).
- Returns an integer representing the count of set bits.
- Use Cases: Bit manipulation tasks, such as counting set bits, checking powers of 2, Hamming distance, or optimizing algorithms in competitive programming.

# Time Complexities for __builtin_popcount

## Notes
- n: Size of the input (in bits, e.g., 32 for int, 64 for long long).
- Hardware-optimized, typically executes in O(1) cycles on modern CPUs with POPCNT instruction.
- Independent of the number of set bits (unlike manual bit-counting loops).

## Operations

1. Popcount (__builtin_popcount, __builtin_popcountl, __builtin_popcountll)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Counts set bits using a single hardware instruction (e.g., POPCNT), constant-time regardless of input size or bit pattern.

# Space Complexity
- O(1): Uses only a constant amount of extra space for computation, regardless of input size.
*/