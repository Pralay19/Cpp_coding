#include<bits/stdc++.h>
using namespace std;

void insrt(stack<int>&stk,int temp){
	if(stk.size()==0 || stk.top()<=temp){
		stk.push(temp);
	}
	int val=stk.top();
	stk.pop();
	insrt(stk,temp);
	stk.push(val);

}

void recur(stack<int>&stk){
	if(stk.size()==1){
		return;
	}
	int temp=stk.top();
	stk.pop();
	recur(stk);
	insrt(stk,temp);
}

int main(){
	stack<int>stk;
	int i;
	while(cin>>i){
		stk.push(i);
	}
	recur(stk);

	for(int i=0;i<stk.size();i++){
		cout<<stk.top()<<" ";
		stk.pop();
	}
}