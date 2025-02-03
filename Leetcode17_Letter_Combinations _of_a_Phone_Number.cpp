*/Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.*/
class Solution { 
public:
string str [8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void helper(string number,int pos,vector<string> &result, string pattern)
{
    if (pos==number.length())
    {
        result.push_back(pattern);
        return;
    }
    
       int digit=number[pos]-'0';
       string patt=str[digit-2];
       for(int j=0;j<patt.length();j++){
        helper(number,pos+1,result,pattern+patt[j]);
    }
    return;
}
    vector<string> letterCombinations(string digits) {
        vector<string> result;
         if(digits.length()==0)
        {
            return result;
        }
         helper(digits,0,result,"");
         return result;
    }
};
