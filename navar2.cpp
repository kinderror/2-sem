#include <iostream>

using namespace std;

void calc_optimals(int *prices, int *optimals, int L, int n) {
    optimals[0] = 0;
    for (int i = 1; i < L + 1; i++) {
        int max_price = 0;
        for (int j = 1; j < n + 1; j++) {
            if (i >= j) {
                max_price = max(optimals[i - j] + prices[j], max_price);
            }
        }
        optimals[i] = max_price;
    }
}

void cuts(int *prices, int *optimals, int L, int n) {
    while (L != 0) {
        for (int i = 1; i < n + 1; i++) {
            if (L >= i and optimals[L - i] + prices[i] == optimals[L]) {
                cout << i << " ";
                L -= i;
            }
        }
    }
    
}

int main() {
    int L, n;
    cin >> L >> n; // n = 10
    int *prices = new int[n + 1]; // 1 5 8 9 10 17 17 20 24 30
    int *optimals = new int[L + 1];
    for (int i = 1; i < n + 1; i++) {
        cin >> prices[i];
    }
    calc_optimals(prices, optimals, L, n);
    cuts(prices, optimals, L, n);
    delete [] prices;
    delete [] optimals;
    return 0;
}
