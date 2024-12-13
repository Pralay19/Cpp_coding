#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findijk(vector<int>&arr){
	vector<vector<int>>ans;
	unordered_map<int,int>mpp;
	int n=arr.size();
	for(int i=0;i<n;i++){
		mpp[arr[i]]=i;	
	}

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int l=j;l<n;l++){
				if(i==j || j==l || i==l) continue;
				int rem=arr[i]-2*arr[j]+3*arr[l];
				if(mpp.find(rem)!=mpp.end()){
					ans.push_back({i,j,mpp[rem],l});
				}
			}
		}
	}
	return ans;

}

int main(){
	vector<int>arr;
	int i;
	while(cin>>i){
		arr.push_back(i);
	}
	vector<vector<int>>ans=findijk(arr);

	for(auto it:ans){
		for(auto it2:it){
			cout << it2<<" ";
		}
		cout <<endl;
	}
}