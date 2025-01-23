#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  // Write C++ code here
  // int numbers[]={1,2,9};
  vector<int> numbers = {9, 9, 9};
  int n = numbers.size();
  int carry = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    if (i == 0)
    {
      if (numbers[i] == 9 && carry != 0)
      {
        numbers[i] = 0;
        carry = 1;
      }
      else
      {
        numbers[i] += carry;
        carry = 0;
      }
    }
    else
    {
      if (numbers[i] == 9)
      {
        numbers[i] = 0;
        carry = 1;
      }
      else
      {
        numbers[i] += carry;
        carry = 0;
      }
    }
  }
  cout << "----------------------------numbers after adding 1--------------------------" << endl;
  if (carry == 1)
  {
    numbers.insert(numbers.begin(), 1);
  }
  n = numbers.size();
  for (int i = 0; i < n; i++)
  {

    cout << numbers[i] << " ";
  }

  return 0;
}
