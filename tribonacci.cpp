#include <iostream>

using namespace std;

int tribonacci(int N) {
    int *num = new int[3];
    num[0] = 0;
    num[1] = 1;
    num[2] = 1;
    int curr = num[N];
    for (int i = 3; i < N + 1; i++) {
        curr = num[0] + num[1] + num[2];
        num[0] = num[1];
        num[1] = num[2];
        num[2] = curr;
    }
    delete [] num;
    return curr;
} 

int main() {
    int N;
    cin >> N;
    cout << tribonacci(N);
    return 0;
}
