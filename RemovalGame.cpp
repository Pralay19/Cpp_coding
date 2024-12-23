// #include <bits/stdc++.h>
// using namespace std;
// const int N=5001;

// int dp[N][N];
// int rec(int a[],int l,int r){
// 	if(l==r) return a[l];
// 	if(r-l==1) return max(a[l],a[r]);

// 	int &ans=dp[l][r];
// 	if(ans!=-1) return ans;
// 	ans=max(a[l]+min(rec(a,l+2,r),rec(a,l+1,r-1)),
// 			a[r]+min(rec(a,l,r-2),rec(a,l+1,r-1)));

// return ans; 
// }
// // int game(int n, vector<int>& nums) {
// //     // Initialize DP table
//     // vector<vector<int>> dp(n, vector<int>(n, 0));

// //     // Base cases
// //     for (int i = 0; i < n; i++) {
// //         dp[i][i] = nums[i]; // Single element subarray
// //     }
// //     for (int i = 0; i < n - 1; i++) {
// //         dp[i][i + 1] = max(nums[i], nums[i + 1]); // Subarray of size 2
// //     }

// //     // Fill DP table for subarrays of size 3 or more
// //     for (int len = 3; len <= n; len++) { // Length of subarray
// //         for (int i = 0; i <= n - len; i++) {
// //             int j = i + len - 1; // Endpoint of subarray
// //             dp[i][j] = max(
// //                 nums[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), // Pick nums[i]
// //                 nums[j] + min(dp[i][j - 2], dp[i + 1][j - 1])  // Pick nums[j]
// //             );
// //         }
// //     }

// //     return dp[0][n - 1];
// // }

// int main() {
//     int n;
//     cin >> n;
//     int nums[n];
//     for (int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }
//     memset(dp,-1,sizeof(dp));
//     cout << rec(nums,0,n-1) << endl;
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  long long sum = 0;
  for (int&v : x) {
    cin >> v;
    sum += v;
  }

  vector<vector<long long>> dp(n,vector<long long>(n));
  for (int l = n-1; l >= 0; l--) {
    for (int r = l; r < n; r++) {
      if (l == r) {
	dp[l][r] = x[l];
      } else {
	dp[l][r] = max(x[l]-dp[l+1][r],
		       x[r]-dp[l][r-1]);
      }
    }
  }
  cout << (sum+dp[0][n-1])/2 << endl;
}