//Given a number N. Find the length of the longest consecutive 1s in its binary representation.

class Solution
{
    public:
    int maxConsecutiveOnes(int n)
    {
        // code here
        int max=0;
        int current=0;
        
        while(n>0)
        {
           if((n&1)==0)
           {
               max=current>max?current:max;
               current=0;
           }
           else
           {
               current++;
           }
           n=n>>1;
            
        }
        max=current>max?current:max;
        return max;
    }
};
