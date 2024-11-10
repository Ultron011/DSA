/*
    INPUT - 
        [1, 1, 2, 2, 3, 3, 4]
    OUTPUT -
        MODIFY ARRAY - [1, 2, 3, ... ]
        PRINT - 3 (no. of unique elements)
*/

/*
    Time Complexity  - 
        O(nlog(n) + n)
    Space Complexity - 
        O(n)
*/


#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr) {
    set<int> st;
    for (int i = 0; i < arr.size(); i++) {
        st.insert(arr[i]);
    }

    int index = 0;
    for(auto it : st) {
        arr[index++] = it;
    }

    return index;
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