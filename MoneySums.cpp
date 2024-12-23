#include<bits/stdc++.h>
using namespace std;

set<int>st;
void sums(int total,vector<int>&nums){
	for(int i=0;i<n;i++){
		set<int> temp_st;
		for(auto it:st){
			int ans=nums[i]+it;
			// st.insert(ans);
			temp_st.insert(ans);
		}
		st.insert(temp_st.begin(), temp_st.end());
	}

}


int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	int total=0;
	for(int i=0;i<n;i++){
		cin>>nums[i];
		total+=nums[i];
	}
	st.insert(0);
	// vector<int>dp(total+1,-1);
	sums(total,nums);
	st.erase(0);
	cout<<st.size()<<endl;
	for(auto it:st){
		cout<<it<<" ";
	}
}