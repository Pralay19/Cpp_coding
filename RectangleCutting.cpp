#include<bits/stdc++.h>
using namespace std;

int cutting(int a,int b){
	vector<vector<int>>dp(a+1,vector<int>(b+1,1e6));
	// dp[i][j]=min number of cuts to break a block 
	// of i*j into squares
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			//i->height
			//j->width
			if(i==j){
				dp[i][i]=0;
				continue;
			}
			//making a vertical cut
			for(int v=1;v<=i-1;v++){
				dp[i][j]=min(dp[i][j],dp[v][j]+dp[i-v][j]+1);
			}
			//making a horizontal cut
			for(int h=1;h<=j-1;h++){
				dp[i][j]=min(dp[i][j],dp[i][h]+dp[i][j-h]+1);
			}
		}
	}
return dp[a][b];
}

int main(){
	int a,b;
	cin>>a>>b;

	cout<<cutting(a,b);
}