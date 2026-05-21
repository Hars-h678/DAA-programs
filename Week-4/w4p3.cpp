#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

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
        int k;
        cin >> k;
        if (k >= n) {
            cout << "Not Present\n";
            continue;
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            if (k == 1) {
                cout << arr[i] << "\n";
                break;
            }
            k--;
        }
    }
    return 0;
}
