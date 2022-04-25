#include <iostream>
#include <algorithm>

using namespace std;

void make_heap(int data[], int n, int i) {
    int max = i, l = 2 * i + 1, r = 2 * i + 2;   
    if (l < n and data[l] > data[max]) max = l;
    if (r < n and data[r] > data[max]) max = r;
    if (max != i) {
        swap(data[i], data[max]);
        make_heap(data, n, max);
    }
}

void heap_sort(int data[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        make_heap(data, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(data[0], data[i]);
        make_heap(data, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    int data[n];
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    heap_sort(data, n);
    for (int i = 0; i < n; i++) {
        cout << data[i] << ' ';
    }
    return 0;
}
