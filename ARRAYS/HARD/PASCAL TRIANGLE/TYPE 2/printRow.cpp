/*
    Problem Statement: Find an Element in Pascal's Triangle
        Given a specific row number (r) , 
        Write a function to print all the elements of that row
    
    Pascal's Triangle - 
            1
           1, 1
          1, 2, 1
        1, 3, 3, 1
       1, 4, 6, 4, 1
        
        
    Input - 
        r = 4
    
    Output -
        1, 3, 3, 1
    
    Explanation -
        The elements at row number 4 are - 1, 3. 3, 1
*/

/*
    Time complexity - 
        O(n*r)
    
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

void pascalTriangle(int n) {
    for (int c = 1; c <= n; c++) {
        cout << nCr(n-1, c-1) << " ";
    }
    cout << "\n";
}

int main() {

  int n;
  cin >> n;

  pascalTriangle(n);

  return 0;
}