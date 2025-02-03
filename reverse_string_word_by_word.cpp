#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
   string str="Bob likes Alice";
   string result="";
  
   int currIndex=0;
   while(currIndex<str.length()){
    int start=currIndex;
     while(currIndex<str.size() &&str[currIndex]!=' '){
        currIndex++;
         }
   if(currIndex==str.length()){
    result=str.substr(start,currIndex-start)+result;
    break;
   }else{
       result =" "+str.substr(start, currIndex-start) + result;
       currIndex++;
   }
   }
   cout<<result<<endl;
    
    return 0;
}
