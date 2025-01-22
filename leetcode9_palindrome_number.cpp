class Solution {
public:
    bool isPalindrome(int n) {
    if(n<0){return false;}
    if(n==0){return true;};
    int left=floor(log10(n));
    left=pow(10,left);
    int right=10;
    while(left>=right)
    {
      if(n/left!=n%10)
      {
          return false;
      }
      n%=left;
      n/=10;
      left/=100;
    }
    return true;
    }
};
