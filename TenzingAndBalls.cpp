#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, mx = 200005;
        int a[mx], dp[mx], b[mx];
        cin >> n;
        dp[0] = 0;
        fill(b, b + n + 1, INT_MAX);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            dp[i] = min(dp[i - 1] + 1, b[a[i]]);
            b[a[i]] = min(b[a[i]], dp[i - 1]);
        }
        cout << n - dp[n] << '\n';
    }
}
