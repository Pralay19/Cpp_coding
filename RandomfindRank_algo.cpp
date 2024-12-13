#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr,int l,int r){
	int i=l+1,j=r;
	int pivot=arr[l];
	while(i<=j){
		while(i<=j && arr[i]<=pivot) i++; 
		while(i<=j && arr[j]>pivot) j--;
		if(i<j){
			swap(arr[i],arr[j]);
			i++;j--;
		}
	}
	i--;
	swap(arr[l],arr[i]);
	return i;
}

int randomfindRank(vector<int>&arr,int l,int r,int rank){
	int pivot_index=rand()%(r-l+1)+l;
	swap(arr[l],arr[pivot_index]);
	int k=partition(arr,l,r);
	int rank_of_pivot=r-k+1;
	// here we are just considering one side
	if(rank_of_pivot==rank) return arr[k];
	else if(rank<rank_of_pivot) return randomfindRank(arr,k+1,r,rank);
	else return randomfindRank(arr,l,k-1,rank-rank_of_pivot);

}

int main(){
	int n,k;
	cin >>n >>k;
	vector<int>arr(n);
	int i;
	while(cin>>i) arr.push_back(i);
	cout << randomfindRank(arr,0,n-1,k);
}