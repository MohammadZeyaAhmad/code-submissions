#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
   string str="Hello_world!";
   cout<<"  ";
   for(int i=1;i<str.length();i+=4){
    cout<<str[i]<<"     ";
   }
   cout<<endl;
   for (int i = 0; i < str.length(); i+=2)
   {
       cout << str[i] << "  ";
   }
   cout<<endl<<"     ";
   for (int i = 3; i < str.length(); i+=4)
   {
       cout << str[i] <<"     ";
   }
}
