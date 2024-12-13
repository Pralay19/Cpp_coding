#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int countWays(int n, int x, vector<int>& coins) {
    vector<int> dp(x + 1, 0);
    dp[0] = 1; // Base case: 1 way to make sum 0 (use no coins)

    for (int j = 1; j <= x; j++) { // Iterate through all possible sums
        for (auto coin : coins) {
            if (j >= coin) {
                dp[j] = (dp[j] + dp[j - coin]) % MOD;
            }
        }
    }

    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << countWays(n, x, coins) << endl;

    return 0;
}
