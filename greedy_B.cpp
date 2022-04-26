#include <iostream>

using namespace std;

int main() {
    int S, K, n, N = 0;
    cin >> S >> K >> n;
    int petrol[n + 2];
    petrol[0] = 0;
    petrol[n + 1] = S;
    for (int i = 0; i < n; i++) {
        cin >> petrol[i + 1];
    }
    int k = K;
    for (int i = 0; i < n + 1; i++) {
        if (petrol[i + 1] - petrol[i] > K) {
            cout << -1;
            return 0;
        }
        k -= petrol[i + 1] - petrol[i];
        if (k < 0) {
            k = K;
            N++;
            i--;
        }
    }
    cout << N;
    return 0;
}
