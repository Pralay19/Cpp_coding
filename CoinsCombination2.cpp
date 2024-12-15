#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

//ITERATIVE APPROACH
// int countWays(int x,vector<int>&coins){

//     int n=coins.size();
// 	vector<vector<int>>dp(n+1,vector<int>(x+1));

//     //base cases
//     for(int i=0;i<n;i++){
//         dp[i][0]=1;
//     }
//     //state
//     for(int i=n-1;i>=0;i--){
//         for(int k=1;k<=x;k++){
//             int notpick=dp[i+1][k];
//             int pick=0;
//             if(coins[i]<=k){
//                 pick=dp[i][k-coins[i]];
//             }
//             dp[i][k]=(pick+notpick)%MOD;
//         }
//     }
//     return dp[0][x];
// }

//RECURSIVE APPROACH
int countWays(int k,int i,vector<int>&coins,vector<vector<int>>&dp){
    if(k==0) return 1;
    if(k<0) return 0;
    if(i==coins.size()) return 0;
    if(dp[i][k]!=-1) return dp[i][k];

    int notpick=countWays(k,i+1,coins,dp);
    int pick=0;
    if(coins[i]<=k){
        pick=countWays(k-coins[i],i,coins,dp);
    }
    int result=(pick+notpick)%MOD;
    return dp[i][k]=result;

}

int main(){
	int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
    
    cout << countWays(x,0,coins,dp) << endl;
}