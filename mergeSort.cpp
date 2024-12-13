#include<bits/stdc++.h>
using namespace std;
	
 void insrt(vector<int>&arr,int temp){
 	if(arr.size()==0 || arr[arr.size()-1]<=temp){
 		arr.push_back(temp);
 	}
 	int val=arr[arr.size()-1];
 	arr.pop_back();
 	insrt(arr,temp);
 	arr.push_back(val);

 }	

void recur(vector<int>&arr){
	if(arr.size()==1){
		return ;
	}
	int temp=arr[arr.size()-1];
	arr.pop_back();
	recur(arr);
	insrt(arr,temp);
}

int main(){
	vector<int>arr;
	int i;
	while(cin>>i){
		arr.push_back(i);
	}
	recur(arr);
	for(auto i:arr){
		cout<<i << " ";
	}
}