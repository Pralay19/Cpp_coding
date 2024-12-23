#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;

// Recursive Approach
// int findSets(int i,int w,vector<vector<int>>&dp){
// 	if(w==0) return 1;
// 	if(w<0) return 0;
// 	if(i<=0) return 0;

// 	if(dp[i][w]!=-1) return dp[i][w];
// 	int pick=0,notpick=0;
// 	if(w>=i)
// 		pick=findSets(i-1,w-i,dp);
// 	notpick=findSets(i-1,w,dp);
// 	return dp[i][w]=(pick+notpick)%MOD ;
// }


int main(){
	int n;
	cin>>n;
	int totalsum=(n*(n+1))/2;
	if (totalsum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
	int target=totalsum/2;
	vector<vector<int>>dp(n+1,vector<int>(target+1));
	// cout<<findSets(n,target,dp)/2;

	for(int i=0;i<=n;i++){
		dp[i][0]=1;
	}
	for(int i=0;i<=target;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int w=1;w<=target;w++){
			dp[i][w]=dp[i-1][w];
			if(w>=i)
				dp[i][w]=(dp[i][w]+dp[i-1][w-i])%MOD;
		}
	}
	cout<<dp[n][target];
}