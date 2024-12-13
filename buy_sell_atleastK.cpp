#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>&arr,int k){
	int n=arr.size();
	if(n==0) return 0;
	if(n<=k) return 0;
	vector<int>minprice(n,0);
	minprice[0]=arr[0];
	for(int i=1;i<n;i++){
		minprice[i]=min(arr[i],minprice[i-1]);
		cout <<minprice[i]<<" ";
	}
	cout<<endl;
	int maxprofit=0;
	for(int i=k;i<n;i++){
		maxprofit=max(maxprofit,arr[i]-minprice[i-k]);
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