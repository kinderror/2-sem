#include <iostream>

using namespace std;

int main() {
    int n, N = 0;
    cin >> n;
    int *lections = new int[2 * n];
    for (int i = 0; i < 2 * n; i++) {
        cin >> lections[i];
    }
    int end = lections[0];
    for (int i = 0; i < n; i++) {
        if (lections[2 * i] >= end) {
            end = lections[2 * i + 1];
            N++;
        }
    }
    delete [] lections;
    cout << N;
    return 0;
}
