// Given an unsigned integer N. The task is to swap all odd bits with even bits. For example, if the given number is 23 (00010111), it should be converted to 43(00101011).

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int x)
    {
       int even_bits = x & 0xAAAAAAAA; 
     
        // Get all odd bits of x
        int odd_bits = x & 0x55555555; 
     
        // Right shift even bits
        even_bits >>= 1; 
         
        // Left shift even bits
        odd_bits <<= 1; 
         
        // Combine even and odd bits
        return (even_bits | odd_bits); 
    }
};
