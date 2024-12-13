#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

const int MAX_N = 1e5 + 5;
int n;
vector<int> h(MAX_N), dp(MAX_N, -1); // Initialize dp array with -1 for memoization

// Top-down recursive function to find minimum cost to reach the ith stone
int solve(int i) {
    if (i == 1) return 0;           // Base case: no cost at the first stone
    if (dp[i] != -1) return dp[i];   // Return already computed value if exists

    // Recurrence relation with memoization
    int cost = solve(i - 1) + abs(h[i] - h[i - 1]);
    if (i > 2) {
        cost = min(cost, solve(i - 2) + abs(h[i] - h[i - 2]));
    }
    
    dp[i] = cost; // Memoize the result
    return dp[i];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }

    cout << solve(n) << endl; // Output the minimum cost to reach the nth stone
    return 0;
}
