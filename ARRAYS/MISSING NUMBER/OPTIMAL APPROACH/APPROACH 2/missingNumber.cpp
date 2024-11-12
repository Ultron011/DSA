/*
   Explanation - 
        To solve this question, we will use a property of xor operator .
        Now xor of two identical numbers will always result in a 0 or we can 
        say that xor of two same numbers cancels each other out.
        So we will use this property to find the missing number in the array.
        We will first calculate the xor of all the numbers in the array and 
        then xor of all the numbers from 1 to n (where n is the size of the array). 
        The xor of these two will give us the missing number.


  Time complexity - 
      O(n)
  Space complexity -
      O(1)
*/


#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> arr, int n) {
    int xorSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        xorSum ^= arr[i];
        xorSum ^= i + 1;
    }
    xorSum ^= n;

    return xorSum;
}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n-1);
  for (int i = 0; i < n-1; i++) {
    cin >> arr[i];
  }

  cout << "The missing Number is : " << missingNumber(arr, n) << endl;

  return 0;
}