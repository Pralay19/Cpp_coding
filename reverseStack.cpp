#include<bits/stdc++.h>
using namespace std;

void insrt(stack<int>&stk,int temp){
	if(stk.size()==0){
		stk.push(temp);
		return;
	}
	int val=stk.top();
	stk.pop();
	insrt(stk,temp);
	stk.push(val);
}

void reverse(stack<int>&stk){
	if(stk.size()==1){
		return;
	}
	int temp=stk.top();
	stk.pop();
	reverse(stk);
	insrt(stk,temp);

}

int main(){
	stack<int>stk;
	int i;
	while(cin>>i){
		stk.push(i);
	}


	//reverse(stk);

	while(!stk.empty()){
		cout<<stk.top()<<" ";
		stk.pop();
	}
}