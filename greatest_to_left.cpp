#include<bits/stdc++.h>
using namespace std;

void greatest_left(vector<int>&arr,vector<int>&ans){
	int n=arr.size();
	stack<int>stk;
	stk.push(0);
	for(int i=n-1;i>=0;i--){
		while( !stk.empty() && arr[stk.top()]<arr[i]){
			ans[stk.top()]=i;
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty()){
		ans[stk.top()]=-1;
		stk.pop();
	}
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