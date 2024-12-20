#include<bits/stdc++.h>
using namespace std;

int edit(string str1,string str2){

	vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1));
	dp[0][0]=0;
	for(int i=1;i<=str1.size();i++){
		dp[i][0]=i;
		//i characters are remaining in the first string but 0 characters
		//are reminaing in the second string.
	}
	for(int i=0;i<=str2.size();i++){
		dp[0][i]=i;
		//i characters are remaining in the second string but 0 characters are remaining
		//in the first string.
	}
	for(int i=1;i<=str1.size();i++){
		for(int j=1;j<=str2.size();j++){
			if(str1[i-1]==str2[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}
			else{
				//(replace),(remove from first string),(remove from second string)
				dp[i][j]=min({dp[i-1][j-1]+1,dp[i-1][j]+1,dp[i][j-1]+1});
				//We have taken only these transitions because some transition mean the same
				//thing. For example abcd,xyze 2 strings are there and we add 'e' character
				//to the first string abcde, now our problem come down to abcd and xyz,
				//in other words it can also mean that we removed a character from the second
				//string. So in this way some transitions mean the same thing and it simply 
				//boils down to these transitions only.
			}
		}
	}
	return dp[str1.size()][str2.size()];
}
int main(){
	string str1,str2;
	cin>>str1>>str2;

	cout<<edit(str1,str2);
}