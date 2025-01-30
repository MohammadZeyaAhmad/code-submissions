/*Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
*/
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result=0;
        int n=columnTitle.length();
        for(int i=0;i<n;i++)
        {
            result=result*26+(columnTitle.at(i)-'A'+1);
        }
        return result;
    }
};

