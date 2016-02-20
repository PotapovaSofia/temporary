#include <iostream>
#include <vector>
#include <tgmath.h>

using namespace std;

int main() {
    int c;
    cin >> c;
    if (c==0) {
        cout << 1 << endl << 0;
    }
    int x = c, k = 0;
    vector<int> v;
    while (x) {
        v.push_back(x % 10);
        x = x / 10;
        k++;

    }
    int max = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= max) {
            max = v[i];
        }
    }
    cout << max << endl;
    vector<vector<int>> A (max);

    for (int i = 0 ; i < A.size(); i++) {
        for (int j = 0; j < k; j++) {
            if (v[j]) {
                A[i].push_back(1);
                v[j]--;
            } else {
                A[i].push_back(0);
            }
        }
    }
    for (int i = 0; i < A.size(); i++) {
        int k = 0;
        for (int j = 0; j < A[i].size(); j++) {
            k += A[i][j] * pow(10, j);
        }
        cout << k << " ";
    }
    return 0;
}