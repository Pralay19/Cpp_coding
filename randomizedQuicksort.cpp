#include<bits/stdc++.h>
using namespace std;


int partition(vector<int>&arr,int l,int r){
	int pivot=arr[l],i=l+1,j=r;
	while(i<=j){
		//now we will skip all the elements which are smaller or greater than
		// pivot and stopping when it is opposite, that is where we need to swap
		//the i , j elements to satisfy the pivot property.
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
void randQS(vector<int>&arr,int l,int r){
	if(l<r){
		int p=l+rand()%(r-l+1);
		//below we are placing(swapping) the pivot at l so as to apply partition on it, 
		//which means that the array from l-to-r will now be partitioned into two halves and 
		//he basis of a random element that we chose. 
		swap(arr[l],arr[p]);
		int k=partition(arr,l,r);
		randQS(arr,l,k-1);
		randQS(arr,k+1,r);
	}
}

int main(){
	vector<int>arr;
	int i;
	while(cin>>i){
		arr.push_back(i);
	}
	int n=arr.size();

	randQS(arr,0,n-1);

	for(auto c:arr){
		cout<<c<< " ";
	}

}