#include<bits/stdc++.h>
using namespace std;

// int maxpages(int n,int x,vector<int>&books,vector<int>&pages){
// 	vector<vector<int>>dp(n+1,vector<int>(x+1,0));

// 	for(int i=1;i<=n;i++){
// 		for(int j=0;j<=x;j++){
// 			int pick=(j>=books[i-1]?dp[i-1][j-books[i-1]]+pages[i-1]:0);
// 			int notpick=dp[i-1][j];
// 			dp[i][j]=max(notpick,pick);
// 		}
// 	}
// return dp[n][x];
// }

int maxpages(int i,int x,vector<int>&books,vector<int>&pages,vector<vector<int>>&dp){

	if(i==0 or x==0) return 0;
	if(dp[i][x]!=-1) return dp[i][x];
	int pick=0,notpick=0;
	if(books[i-1]<=x){
		pick=pages[i-1]+maxpages(i-1,x-books[i-1],books,pages,dp);
	}
	notpick=maxpages(i-1,x,books,pages,dp);

	return dp[i][x]=max(pick,notpick);
}
int main(){
	int n,x;
	cin>>n>>x;
	vector<int>books(n);
	int i=0;
	while(i<n){
		cin>>books[i];
		i++;
	}
	i=0;
	vector<int>pages(n);
	while(i<n){
		cin>>pages[i];
		i++;
	}
	vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
	cout<<maxpages(n,x,books,pages,dp);
}