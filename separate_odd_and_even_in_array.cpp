#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    int numbers[]={1,7,2,4,8,11,16,9,17,14};
    int n=sizeof(numbers) / sizeof(numbers[0]);
    int left=0;
    int right=n;
    while(right>left)
    {
        if(numbers[left]%2!=0 && numbers[right]%2!=0)
        {
            right--;
        }else if(numbers[left]%2==0 && numbers[right]%2==0)
        {
            left++;
        } else if(numbers[left]%2!=0 && numbers[right]%2==0)
        {
            int temp=numbers[left];
            numbers[left]=numbers[right];
            numbers[right]=temp;
            left++;
            right--;
        }else{
            right--;
        }
    }
    cout<<"----------------------------numbers after rearragement------------------------"<<endl;
      for(int i=0;i<n;i++)
    {
    
      cout<< numbers[i]<<" ";
    }
    
    

    return 0;
}
