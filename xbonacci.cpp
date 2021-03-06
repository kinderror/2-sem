#include <iostream>

using namespace std;

void xbonacci(int *start, int size, int n) {
    if (size == 0) {
        return;
    } else if (n < size + 1) {
        for (int i = 0; i < n; i++) {
            cout << start[i] << " ";
        }
        return;
    }
    int *num = new int[n];
    num[size] = 0;
    for (int i = 0; i < size; i++) {
        num[i] = start[i];
        num[size] += start[i];
    }
    for (int i = size + 1; i < n; i++) {
        num[i] = 2 * num[i - 1] - num[i - size - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    delete [] num;
}  

int main() {
    int size, n;
    cin >> size >> n;
    int *start = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> start[i];
    }
    xbonacci(start, size, n);
    delete [] start;
    return 0;
}
