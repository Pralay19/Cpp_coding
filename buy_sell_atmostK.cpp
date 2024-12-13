#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>&arr,int k){
	int n=arr.size();
	if(n==0) return 0;
	if(n<=k) return 0;
	int maxprofit=0;
	int minprice=INT_MIN;
	for(int i=0;i<n;i++){
		if(i>k){
			minprice=min(minprice,arr[i-k]);
		}
		else{
			
		}
	}
	return maxprofit;

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