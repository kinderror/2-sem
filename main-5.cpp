#include <iostream>
#include <algorithm>

using namespace std;

unsigned partition_by_number(int data[], int l_idx, int r_idx, int pivot) {
    while(true) {
        while (data[l_idx] < pivot) ++l_idx;
        while (pivot < data[r_idx]) --r_idx;
        if (r_idx <= l_idx) {
            return r_idx;
        }
        swap(data[l_idx++], data[r_idx--]);
    }
    return r_idx;
}

void quick_sort(int data[], int l_idx, int r_idx) {
    if (!(l_idx < r_idx)) {
        return;
    }
    auto split_idx = partition_by_number(data, l_idx, r_idx, data[l_idx + (r_idx - l_idx) / 2]);
    quick_sort(data, l_idx, split_idx);
    quick_sort(data, split_idx + 1, r_idx);
}

int main() {
    int n;
    cin >> n;
    int data[n];
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    quick_sort(data, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << data[i] << ' ';
    }
    return 0;
}
