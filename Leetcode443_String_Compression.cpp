/* Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.*/

class Solution {
public:
  
    int compress(vector<char>& chars) {
        int new_length=0;
        int i=0;

        while(i<chars.size())
        {
           int j=i+1;
           int count=1;
           new_length++;
           while(j< chars.size() && chars[j]==chars[i]){
            count++;j++;}
           string num = to_string(count);  // Treat the number as a string
           if(count>1)
           {
              int temp=i+1;
              
              for(int i=0;i<num.size();i++)
              {
                new_length++;
                chars[temp++]=num[i];
                count/=10;
              }
              chars.erase(chars.begin()+temp,chars.begin()+j);
              i=temp;
           }else
           {
            i++;
           }
           
        
    }
    return chars.size();
    }
};
