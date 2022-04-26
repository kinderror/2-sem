#include <iostream>

using namespace std;

int main() {
    int S, N = 0;
    cin >> S;
    int money[] = {1, 5, 25, 50, 100};
    for (int i = 4; i >= 0; i--) {
        N += S / money[i];
        S = S % money[i];
    }
    cout << N;
    return 0;
}
