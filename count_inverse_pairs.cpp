#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int>&arr,int x){
	int n=arr.size();
	int l=0,r=1;
	int count=0;
	while(l<n-1 && r<n){
		int rem=arr[r]-arr[l];
		if(rem>x){
			count+=n-r;
			l++;
		}
		else{
			r++;
		}
		if(r<=l){
			r=l+1;
		}

	}
	return count;
}

int main(){
	vector<int>arr;
	int i,x;
	cin>>x;
	while(cin>>i){
		arr.push_back(i);
	}
	cout << countPairs(arr,x);
}