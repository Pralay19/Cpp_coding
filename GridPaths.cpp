#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;

int paths(int n,vector<vector<int>>&grid){
	
}

int main(){
	int n;
	cin>>n;

	vector<vector<int>>grid(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char c;
			cin>>c;
			if(c=='*'){
				grid[i][j]=0;
			}
			else{
				grid[i][j]=1;
			}
		}
	}
	cout<<paths(n,grid);
}