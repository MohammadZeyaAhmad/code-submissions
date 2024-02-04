// Given an integer x, return true if x is a palindrome, and false otherwise.


class Solution {
public:
    bool isPalindrome(int x) {
        long long  rev=0;
        int temp=x;
        while(temp>0)
        {
            if(rev>x )
            {
                return false;
            }
            rev=rev*10+temp%10;
            temp=temp/10;
        }

        return rev==x;
    }
};
