#include<bits/stdc++.h>
using namespace std;

// int minSteps(int x,vector<int>&dp){
// 	if(x==0) return 0;
// 	if(dp[x]!=-1) return dp[x];
	
// 	int result=INT_MAX;
// 	int number=x;
// 	while(number>0){
// 		int digit=number%10;
// 		if(digit==0){
// 			number=number/10;
// 			continue;
// 		}
// 		int dans=1+minSteps(x-digit,dp);
// 		result=min(result,dans);
// 		number=number/10;
// 	}
// return dp[x]=result;
// }

int minSteps(int n){
	vector<int>dp(n+1,1e9);
	dp[0]=0;
	int result=INT_MAX;
	for(int i=1;i<=n;i++){
		string num=to_string(i);
		for(char c:num){
			int digit=c-'0';
			if(digit!=0){
				dp[i]=min(dp[i],dp[i-digit]+1);
			}
		}
	}
	return dp[n];
}

int main(){
	int n;
	cin>>n;

	
	cout<<minSteps(n);
}