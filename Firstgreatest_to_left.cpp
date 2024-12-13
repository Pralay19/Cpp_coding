#include<bits/stdc++.h>
using namespace std;

void greatest_left(vector<int>&arr,vector<int>&ans){
	
}

int main(){
	vector<int>arr;
	int i;
	while(cin>>i)
	{
		arr.push_back(i);
	}
	int n=arr.size();
	vector<int>ans(n,0);
	greatest_left(arr,ans);

	for(auto p:ans){
		cout <<p<<" ";
	}
}