#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int>arr;
	int i;
	while(cin>>i){
	arr.push_back(i);
	}	

	int sum=0;
	int maxSum=INT_MIN;
	int n=arr.size();
	for(int i=0;i<n;i++){
		sum+=arr[i];
		if(sum<0){
			sum=0;
		}
		maxSum=max(maxSum,sum);
	}

	cout<<maxSum;
	
}