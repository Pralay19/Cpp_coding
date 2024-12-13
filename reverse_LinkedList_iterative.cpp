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

Node* reverse(Node*root){
	if(root==nullptr) return nullptr;

	Node*prev=nullptr,*cur=root,*temp=nullptr;
	while(cur!=nullptr){
		temp=cur->next;
		cur->next=prev;
		prev=cur;
		cur=temp;
		
	}
	return prev;

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
	temp=new Node(4);
	head->next=temp;

	Node*ans=reverse(root);

	while(ans!=nullptr){
		cout<<ans->val<< " ";
		ans=ans->next;
	}
}