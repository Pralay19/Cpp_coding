#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	char c;
	while(cin>>c){
		s.push_back(c);
	}
	unordered_map<int,int>mpp;
	int prefsum=0,largest_dense=0;
	for(int i=0;i<s.size();i++){
		prefsum+= s[i]=='0'?-1:1;
		if(prefsum>=1) largest_dense=i+1;
		else if(mpp.find(prefsum)==mpp.end()) mpp[prefsum]=i;
		if(mpp.find(prefsum-1)!=mpp.end()){
			if(largest_dense<(i-mpp[prefsum-1])) largest_dense=i-mpp[prefsum-1];
		}
	}

	cout<<largest_dense;
}