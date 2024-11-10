/*
    INPUT - 
        [1, 1, 2, 2, 3, 3, 4]
    OUTPUT -
        MODIFY ARRAY - [1, 2, 3, ... ]
        PRINT - 3 (no. of unique elements)
*/

/*
    Time Complexity  - 
        O(n)
    Space Complexity - 
        O(1)
*/


#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr) {
    int i = 0, j = 1;
    while (j < arr.size()) {
        if (arr[i] == arr[j]) {
            j++;
        } else {
            swap(arr[i+1], arr[j]);
            i++;
            j++;
        }
    }
    return i+1;
}


void printArray(vector<int> arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}


int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    printArray(arr);

    cout << removeDuplicates(arr) << endl;
    printArray(arr);

    return 0;
}