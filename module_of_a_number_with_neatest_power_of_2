#include <iostream>

int moduloWithNearestPowerOf2(int x) {
    // __builtin_clz(x) returns the number of leading zeros in the binary representation of x.
    // For example, for a 32-bit number:
    // Value of x       Binary Representation (32-bit)    __builtin_clz(x)
    // 1                00000000 00000000 00000000 00000001     31
    // 16               00000000 00000000 00000000 00010000     27
    // 77               00000000 00000000 00000000 01001101     25
    // 2147483648       10000000 00000000 00000000 00000000      0

    // The most significant bit (MSB) position is calculated as:
    // position = 31 - __builtin_clz(x)

    int nearestPowerOf2 = 1 << (31 - __builtin_clz(x)); // Get nearest power of 2 using MSB position
    return x & (nearestPowerOf2 - 1);                  // Compute modulo with bitwise AND
}

int main() {
    int x = 77;
    std::cout << "Modulo Result: " << moduloWithNearestPowerOf2(x) << std::endl;
    return 0;
}
