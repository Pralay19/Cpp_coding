#include<bits/stdc++.h>
using namespace std;


void recur(stack<int>&stk,int k){

	if(k==1){
		stk.pop();
		return;
	}
	int val=stk.top();
	stk.pop();
	recur(stk,k-1);
	stk.push(val);	

}

void midDel(stack<int>&stk,int n){
	if(n==0){
		return;
	}

	int k=n/2+1;
	recur(stk,k);
}



int main(){
	stack<int>stk;
	int i;
	while(cin>>i){
		stk.push(i);
	}
	int n=stk.size();
	midDel(stk,n);

	while(!stk.empty()){
		cout<<stk.top()<<" ";
		stk.pop();
	}

}