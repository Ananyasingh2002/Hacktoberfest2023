#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5}; // Coin denominations
    int amount;
    
    cout << "Enter the amount to make change for: ";
    cin >> amount;

    int result = minCoins(coins, amount);
    if (result == -1) {
        cout << "It's not possible to make change for " << amount << " using given coins." << endl;
    } else {
        cout << "Minimum number of coins needed to make change for " << amount << " is: " << result << endl;
    }

    return 0;
}
