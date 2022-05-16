#include <iostream>

void least_coin_up(int *coins, int coins_size, int *optimals, int P) {
    optimals[0] = 0;
    for (int sum = 1; sum != P + 1; sum++) {
        int local_min = numeric_limits<int>::max();
        for (int coin_idx = 0; coin_idx != coins_size; coin_idx++) {
            if (sum >= coins[coin_idx]) {
                local_min = min(optimals[sum - coins[coin_idx]] + 1, local_min);
            }
        }
        optimals[sum] = local_min;
    }
}
int main() {
    
    return 0;
}
