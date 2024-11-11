/*
    Input - 
        [1, 1, 2, 3, 4, 5]
        [2, 3, 4 , 4, 5, 6]

    Output - 
        [1, 2, 3, 4, 5, 6]
*/

/*
     Time complexity - O(n1 +n2)
     Space Complexity - O(n1 + n2)
*/


#include<bits/stdc++.h>
using namespace std;

vector<int> unionOfSortedArrays(vector<int> A, vector<int> B) {
    int n1 = A.size();
    int n2 = B.size();
    int i = 0, j = 0;
    vector<int> result;
    while (i < n1 && j < n2) {
        if (A[i] < B[j]) {
            if (result.size() == 0 || result.back() != A[i]) {
                result.push_back(A[i]);
            }
            i++;
        } else {
            if (result.size() == 0 || result.back() != B[j]) {
                result.push_back(B[j]);
            }
            j++;
        }
    }


    while (i < n1) {
        if (result.size() == 0 || result.back() != A[i]) {
            result.push_back(A[i]);
        }
        i++;
    }

    while (j < n2) {
        if (result.size() == 0 || result.back() != B[j]) {
            result.push_back(B[j]);
        }
        j++;
    }

    return result;
}

void printArray(vector<int> arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main () {

  int n1, n2;
  cin >> n1 >> n2;
  vector<int> A(n1);
  vector<int> B(n2);

  for (int i = 0; i < n1; i++) cin>> A[i];
  for (int i = 0; i < n2; i++) cin>> B[i];

  vector<int> ans = unionOfSortedArrays(A, B);

  printArray(ans);

  return 0;
}