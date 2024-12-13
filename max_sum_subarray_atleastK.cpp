#include<bits/stdc++.h>
using namespace std;

int maxSumSubarray(vector<int>&arr,int k){
	int sum=0,i=0,maxSum=INT_MIN,last=0,n=arr.size();
	for(int j=0;j<n;j++){
		sum+=arr[j];
		if(j-i+1 ==k) maxSum=max(maxSum,sum);
		if(j-i+1 >k){
			maxSum=max(maxSum,sum);
			last+=arr[i];
			if(last<0){
				sum-=last;
				last=0;
				maxSum=max(maxSum,sum);
			}
		}
	}
	return maxSum;
}

int main(){
	 vector<int> nums = {1, 2, 3, -2, 5, -1, 2, 6, -3, 4};
    int k;
    cin>>k;
    int result = maxSumSubarray(nums, k);
    
    if (result != -1) {
        cout<< result;
    }
    
    return 0;
}