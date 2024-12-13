#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>&arr){
	if(arr.size()==0) return 0;
	int buy=0,sell=0;
	int mprofit=0;

	for(int i=1;i<arr.size();i++){
		if(arr[buy]>arr[i]){
			buy=i;
		}
		if(arr[sell]<arr[i]){
			sell=i;
		}
		mprofit=max(mprofit,arr[sell]-arr[buy]);
	}
	return mprofit;
}

int main(){
	vector<int>arr;
	int i;
	while(cin>>i)
	{
		arr.push_back(i);
	}
	int n=arr.size();	

	cout<<maxProfit(arr);
}