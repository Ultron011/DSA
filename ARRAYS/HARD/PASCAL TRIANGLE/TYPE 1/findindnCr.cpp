/*
    Problem Statement: Find an Element in Pascal's Triangle
        Given a specific row number (r) and column number (c) in Pascal's Triangle, 
        write a function to find the value at that position using the binomial coefficient formula:
            nCr = n!/r! * (n-r)!
    
    Pascal's Triangle - 
            1
           1, 1
          1, 2, 1
        1, 3, 3, 1
       1, 4, 6, 4, 1
        
        
    Input - 
        r = 4, c = 2
    
    Output -
        6
    
    Explanation -
        The value at row 4 and column 2 is 4C2 = 6
*/

/*
    Time complexity - 
        O(r)
    
    Space complexity - 
        O(1)

*/

#include<bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int main() {

  int r, c;
  cin >> r >> c;

  cout << "The value at row " << r << " and column " << c << " is : " << nCr(r, c) << endl;
  

  return 0;
}