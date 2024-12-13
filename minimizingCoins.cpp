#include<bits/stdc++.h>
using namespace std;


int minCoin(int x,vector<int>&coins){
	vector<int>dp(x+1,1e9);

	dp[0]=0;
	for(int i=1;i<=x;i++){
		for(auto coin:coins){
			if(coin<=i){
				dp[i]=min(dp[i],dp[i-coin]+1);
			}
		}
	}
	return (dp[x]==1e9)?-1:dp[x];
}

int main(){
	int n,x;
	cin>>n>>x;

	vector<int>coins(n);
	int i=0;
	while(i<n){
		cin>>coins[i];
		i++;
	}
	cout<<minCoin(x,coins);
}