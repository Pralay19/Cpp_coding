#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
bool valid(int x,int m){
	return x>=1 and x<=m;
}

int desc(int n,int m,vector<int>&arr){
	vector<vector<int>>dp(n+1,vector<int>(m+1));

	//base case
	for(int i=1;i<=m;i++){
		if(arr[0]==i or arr[0]==0){
			dp[1][i]=1;
		}
	}
	for(int i=2;i<=n;i++){
		for(int k=1;k<=m;k++){
			if(arr[i-1]!=0 and arr[i-1]!=k){
				dp[i][k]=0;
				continue;
			}
			for(int prev=k-1;prev<=k+1;prev++){
				if(!valid(prev,m)) continue;
				dp[i][k]=(dp[i][k]+dp[i-1][prev])%MOD;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		ans=(ans+dp[n][i])%MOD;
	}
	return ans;
}

int main(){
	int n,m;
	cin>>n>>m;

	vector<int>arr(n);
	int i=0;
	while(i<n){
		cin>>arr[i++];
	}
	cout<<desc(n,m,arr);
}