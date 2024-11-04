#include<bits/stdc++.h>
using namespace std;

int countAndMerge(int arr[], int s, int mid, int e) {
    int n1 = mid - s + 1;
    int n2 = e - mid;

    int *L = new int[n1];
    int *R = new int[n2];
    
    for (int i = 0; i < n1; i++) {
        L[i] = arr[s + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int res = 0;
    int i = 0, j = 0;
    int k = s;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            res += (n1 - i);
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    delete []L;
    delete []R;

    return res;
}

int countInv(int arr[] , int s, int e) {
    int res = 0;
    if (s < e) {
        int mid = s + (e - s) / 2;
        
        res += countInv(arr , s , mid);
        res += countInv(arr , mid + 1 , e);

        res += countAndMerge(arr, s, mid, e);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {

  int arr[] = {5, 45, 16, 8, 95, 12, 46, 2, 53, 62, 15};
  int size = sizeof(arr)/sizeof(arr[0]);

  printArray(arr, size);

  cout << "Inversion Count is : " << countInv(arr, 0, size-1) << endl;



  return 0;
}