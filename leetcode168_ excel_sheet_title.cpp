/* Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
ZY ->701
...
*/

class Solution {
public:
    string convertToTitle(int columnNumber) {
         string result = "";
    while(columnNumber>0){
        columnNumber--;
       int a = columnNumber % 26;
       result=char(a+'A')+result;
       columnNumber/=26;
    }
    
    return result;
    }
};
