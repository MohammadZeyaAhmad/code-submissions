//You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int x=a^b;
        int count=0;
        while(x>0)
        {
            if(x&1!=0)
            {
            count++;
            }
            x=x>>1;
        }
        
        return count;
        
    }
};
