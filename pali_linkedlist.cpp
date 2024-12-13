#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int val;
	Node*next;
	Node(int a){
		val=a;
		next=nullptr;
	}
};

Node*cur;
bool recur(Node*root){
	if(root==NULL) return true;
	
	bool ans=recur(root->next);
	if(root->val!=cur->val) return false;
	cur=cur->next;
	return ans;

}
int main(){
	Node*root=new Node(1);
	Node*head=root;
	Node*temp=new Node(2);
	head->next=temp;
	head=temp;
	temp=new Node(3);
	head->next=temp;
	head=temp;
	temp=new Node(3);
	head->next=temp;
	head=temp;
	temp=new Node(2);
	head->next=temp;
	head=temp;
	temp=new Node(1);
	head->next=temp;

	cur=root;
	cout<<recur(root);

}