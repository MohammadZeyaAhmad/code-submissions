//Given a number N. The task is to check whether it is sparse or not. A number is said to be a sparse number if no two or more consecutive bits are set in the binary representation.
class Solution
{
    public:
    //Function to check if the number is sparse or not.
    bool isSparse(int n)
    {
        // Your code
        return (n&(n<<1))==0;
    }
};
