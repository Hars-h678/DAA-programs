#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void countingSort(const vector<char>& A, vector<char>& B, vector<int>& C, int n, int k) {
    for (int i = 0; i < n; i++) {
        C[A[i] - 'a'] = C[A[i] - 'a'] + 1;
    }
    vector<int> D = C;
    for (int i = 1; i < k; i++) {
        D[i] = D[i - 1] + D[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        B[D[A[i] - 'a'] - 1] = A[i];
        D[A[i] - 'a'] = D[A[i] - 'a'] - 1;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        vector<char> A(n);
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            mx = max(mx, static_cast<int>(A[i] - 'a'));
        }
        mx++;
        vector<char> B(n);
        vector<int> C(mx, 0);
        countingSort(A, B, C, n, mx);
        int dupMax = 1, ind = -1;
        for (int i = 0; i < mx; i++) {
            if (dupMax < C[i]) {
                dupMax = C[i];
                ind = i;
            }
        }
        if (ind != -1) {
            cout << B[ind] << " - " << dupMax << "\n";
        } else {
            cout << "No Duplicates Present\n";
        }
    }
    return 0;
}
