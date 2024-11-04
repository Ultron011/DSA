/*
    You are given a number of stairs. Initally , you are at the 0th stair, and you need
    to reach the Nth stair. Each time you can either climb one step or two steps. You 
    are supposed to return the number of distinct ways in which you can climm from 0th 
    step to Nth step.
*/

#include<bits/stdc++.h>
using namespace std;

int ClimbStairs(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }

    return ClimbStairs(n-1) + ClimbStairs(n-2);
}

int main () {

  int n;
  cout << "Enter the number of stairs: ";
  cin >> n;

  cout << "No. of distinct ways to climb the stairs is : " << ClimbStairs(n) << endl;

  return 0;
}