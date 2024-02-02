//You are given a decimal number N. You need to find the gray code of the number N and convert it into decimal.

class Solution{
    public:
    //  Function to find the gray code of given number n
    int greyConverter(int n)
    {
        
        // Your code here
        return n^(n>>1);
    }
};
