#include<bits/stdc++.h>
using namespace std;

int topdown(int target,vector<int>&coins,vector<int>&dp){
	if(target==0) return 0;

	if(dp[target]!=-1) return dp[target];

	int ans=INT_MAX;
	int result=INT_MAX;
	for(auto coin:coins){
		if(coin<=target){
			ans=topdown(target-coin,coins,dp);
		}
		if(ans!=INT_MAX){
			result=min(result,ans+1);
		}
	}
	dp[target]=(result==INT_MAX)?INT_MAX:result;
	return dp[target];
}


int minNumber(int target,vector<int>&coins){
	vector<int>dp(target+1,-1);
	return topdown(target,coins,dp);
}

int main(){
	int n,target;
	cin>>n>>target;

	vector<int>coins;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		coins.push_back(a);
	}
	long long answer=minNumber(target,coins);
	if(answer==INT_MAX) {
		cout <<-1;
		return 0;
	}

	cout<< answer;
}