//Given two numbers M and N. The task is to find the position of the rightmost different bit in the binary representation of numbers. If both M and N are the same then return -1 in this case.

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        int count=0;
        while(m && n)
        {
            count++;
            if(((m&1)^(n&1))!=0)
            {
                return count;
            }
            m=m>>1;
            n=n>>1;
            if(m==0 || n==0)
            {
                 count++;
               if(((m&1)^(n&1))!=0)
               {
                return count;
               }
                break;
            }
        }
        
        return -1;
    }
    
    
};
