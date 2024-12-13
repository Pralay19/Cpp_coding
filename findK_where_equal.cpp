#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	char c;
	while(cin>>c){
		s.push_back(c);
	}

	int k=-1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') k++;
	}
	cout<<k;
	
}