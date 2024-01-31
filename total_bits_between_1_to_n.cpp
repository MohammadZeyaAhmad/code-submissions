//You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        int count=0;
        
       while(n>0)
       {
           int x=closestPowerOfTwo(n);
           count+=(1<<(x-1))*x+(n-(1<<(x))+1);
           n=n-(1<<(x));
       }
       return count;
    }
    
    int closestPowerOfTwo(int n)
    {
        
        int x=0;
        while((1<<x)<=n)
        {
            x++;
        }
        
        return x-1;
    }
};
