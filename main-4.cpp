#include <iostream>
#include <algorithm>

using namespace std;

void selection_sort(int data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j] < data[min]) min = j;
        }
        if (min != i) swap(data[i], data[min]);
    }
}

int main() {
    int n;
    cin >> n;
    int data[n];
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    selection_sort(data, n);
    for (int i = 0; i < n; i++) {
        cout << data[i] << ' ';
    }
    return 0;
}