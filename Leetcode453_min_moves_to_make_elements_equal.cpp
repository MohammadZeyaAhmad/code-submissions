//Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
//In one move, you can increment n - 1 elements of the array by 1.

class Solution {
public:
    int minMoves(vector<int>& nums) {
         int sum=0;
         int min=INT_MAX;
         for(int i=0;i<nums.size();i++)
         {
            sum+=nums[i];
            if(nums[i]<min)
            {
                min=nums[i];
            }
         }
         return sum- min*nums.size();
         
        
    }
};
