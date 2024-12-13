#include<bits/stdc++.h>
using namespace std;

// int rand(){
// 	random_device rd;
// 	mt19937 gen(rd());
// 	uniform_int_distribution<> disInt(1, 100);
// 	return disInt(gen);
// }

int partition(vector<int>&arr,int l,int r){
	int pivot=arr[l],i=l+1,j=r;
	while(i<=j){
		while(i<=j && arr[i]<=pivot) i++;
		while(i<=j && arr[j]>pivot) j--;
		if(i<j){
			swap(arr[i],arr[j]);
			i++;j--;
		}
	}
	i--;
	arr[l]=arr[i];
	arr[i]=pivot;
	return i;
}
void randQS(vector<int>&arr,int l,int r){
	if(l<r){
		//int p=rand()%(r-l+1)+l;
		//cout<<p<<"random p" << endl;
		//swap(arr[l],arr[p]);
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

	randQS(arr,1,4);

	for(auto c:arr){
		cout<<c<< " ";
	}

}