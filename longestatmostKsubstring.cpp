#include<bits/stdc++.h>
using namespace std;

int longestatmostKsubstr(string s,int k){
	unordered_map<char,int>mpp;
	int longstr=0;
	int n=s.size(),r=0,l=0;
	while(r<n){
		mpp[s[r]]++;
		while(mpp.size()>k){
			mpp[s[l]]--;
			if(mpp[s[l]]==0) mpp.erase(s[l]);
			l++;
		}
		if(mpp.size()<=k){
			longstr=max(longstr,r-l+1);
		}
		r++;
	}
	return longstr;
}

int main(){
	string s;
	cin>>s;
	int k;
	cin>>k;
	cout<<longestatmostKsubstr(s,k);
}