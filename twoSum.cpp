#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> twosum(vector<int>&arr,int sum){

	unordered_map<int,vector<int>>mpp;
	vector<pair<int,int>>ans;
	for(int i=0;i<arr.size();i++){
		mpp[arr[i]].push_back(i);
	}
	for(int i=0;i<arr.size();i++){
		int rem=sum-arr[i];
		if(mpp.find(rem)!=mpp.end()){
			
		}
	}
	return ans;

}
int main(){
	vector<int>arr;
	int sum;
	cin>>sum;
	int i;
	while(cin>>i){
		arr.push_back(i);
	}
	vector<pair<int,int>>ans;

	ans=twosum(arr,sum);
	for(auto p:ans){
		cout<<p.first<< ","<<p.second<<endl;
	}
}