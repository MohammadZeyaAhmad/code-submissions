// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.


class Solution {
public:
    bool isHappy(int n) {
        // while ( n > 9 )
        // {
        //     int temp = n ;
        //     int ans = 0 ;
        //     while ( temp )
        //     {
        //         int digit = temp % 10 ;
        //         temp = temp / 10 ;
        //         ans = ans + ( digit * digit ) ;
        //     }
        //     n = ans ;
        // }
        // if ( n == 1 || n == 7 )  
        //     return true ;
        // return false ;

         int sum = 0, digit;
		//If n starts with 1 return true.
        if(n==1) return true;
		//If n == 0,2,3,4. It is not happy.
        while(n>4){
			//Finding sum of digits^2 inside of n.
            while(n!=0){
                digit = n%10;
                n/=10;
                sum += digit * digit;
            }
			//Check if sum is happy.
            if(sum == 1) return true;
			//Repeat process again.
            n = sum;
            sum = 0;
    }
    return false;
    }
};
