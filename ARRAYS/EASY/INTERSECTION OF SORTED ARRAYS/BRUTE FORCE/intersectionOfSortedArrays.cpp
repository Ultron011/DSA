/*
    Input - 
        [1, 1, 2, 3, 4, 4]
        [2, 3, 4 , 4, 5, 6]

    Output - 
        [2, 3, 4, 4]
*/

/*
    Time complexity - O(n1 * n2)
    Space complexity - O(n2)
*/


#include<bits/stdc++.h>
using namespace std;

vector<int> unionOfSortedArrays(vector<int> A, vector<int> B) {
    vector<int> result;
    int n1 = A.size();
    int n2 = B.size();

    vector<int> visited(n2, 0);
    
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (A[i] == B[j] && visited[j] == 0) {
                result.push_back(A[i]);
                visited[j] = 1;
                break;
            }

            if (B[j] > A[i]) break;
        }
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