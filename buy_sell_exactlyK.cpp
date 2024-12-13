#include<bits/stdc++.h>
using namespace std;


int maxProfit(vector<int>&arr,int k){
	if(arr.size()==0) return 0;
	if(arr.size()<=k) return 0;
	int mprofit=0;
	int n=arr.size();
	for(int i=0;i<n-k;i++){
		mprofit=max(mprofit,arr[i+k]-arr[i]);
	}
	return mprofit;
}

int main(){
	vector<int>arr;
	int k;
	cin>>k;
	int i;
	while(cin>>i)
	{
		arr.push_back(i);
	}
	int n=arr.size();	

	cout<<maxProfit(arr,k);
}