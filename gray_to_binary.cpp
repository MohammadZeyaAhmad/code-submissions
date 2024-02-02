//Given N in Gray Code, find its binary equivalent. Return the decimal representation of the binary equivalent.
class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        
        // Your code here
        int k=closestPowerOfTwo(n);
        k=1<<k;
        int result=k>>1;
        while(k>0)
        {
           result=n^result;
           
           k= k>>1;
           if(k==0)
           {
               return result;
           }
           result=result>>1;
        }
        
        return 0;
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
