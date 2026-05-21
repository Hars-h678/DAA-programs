#include <iostream>
#include <vector>
using namespace std;

int comp = 0, swaps = 0;

void swapValues(vector<int>& arr, int i, int j) {
    swaps++;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partitionArray(vector<int>& arr, int l, int r) {
    int pivot = arr[l];
    int i = l + 1, j = r;
    while (i < j) {
        while (i <= r && arr[i] <= pivot) {
            i++;
            comp++;
        }
        while (arr[j] > pivot) {
            j--;
            comp++;
        }
        if (i < j) {
            swapValues(arr, i, j);
        }
    }
    swapValues(arr, l, j);
    return j;
}

void quickSort(vector<int>& arr, int l, int r) {
    if (l >= r) {
        return;
    }
    int p = partitionArray(arr, l, r);
    quickSort(arr, l, p - 1);
    quickSort(arr, p + 1, r);
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        comp = 0;
        swaps = 0;
        quickSort(arr, 0, n - 1);
        for (int num : arr) {
            cout << num << " ";
        }
        cout << "\nComparisons: " << comp << "\nSwaps: " << swaps << "\n";
    }
    return 0;
}
