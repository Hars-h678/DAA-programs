#include <iostream>
#include <vector>
using namespace std;

void selectionSort(int n, vector<int>& arr) {
    int comp = 0, swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int mn = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mn]) {
                mn = j;
            }
            comp++;
        }
        int temp = arr[i];
        arr[i] = arr[mn];
        arr[mn] = temp;
        swaps++;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\ncomparisons = " << comp << "\nswaps = " << swaps << "\n";
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
        selectionSort(n, arr);
    }
    return 0;
}
