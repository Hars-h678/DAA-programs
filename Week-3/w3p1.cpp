#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int n, vector<int>& arr) {
    int shift = 0, comp = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            comp++;
            shift++;
        }
        arr[j + 1] = key;
        shift++;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\ncomparisons = " << comp << "\nshifts = " << shift << "\n";
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
        insertionSort(n, arr);
    }
    return 0;
}
