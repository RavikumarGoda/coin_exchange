#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int coin_change(int coins[], int n, int amount) {
    int dp[amount+1];
    int used[amount+1];
    dp[0] = 0;
    used[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i-coins[j]] != INT_MAX) {
                if (dp[i-coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i-coins[j]] + 1;
                    used[i] = coins[j];
                }
            }
        }
    }

    if (dp[amount] == INT_MAX) {
        return -1;
    }

    printf("Coins used to make %d cents:\n", amount);
    int i = amount;
    while (i > 0) {
        printf("%d cents x %d\n", used[i], i/used[i]);
        i -= (i/used[i])*used[i];
    }

    return dp[amount];
}

int main() {
    int n, amount;

    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    int coins[n];
    
    printf("Enter the coin denominations: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter the amount of change: ");
    scanf("%d", &amount);
    
    int min_coins = coin_change(coins, n, amount);
    
    printf("Minimum number of coins required to make %d cents: %d\n", amount, min_coins);
    
    return 0;

}

