#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int n){
		data=n;
		left=NULL;
		right=NULL;
	}
};

void PreOrder(struct Node *root){
	if(root==NULL){
		return;
	}
	cout<<(root->data)<<endl;
	PreOrder(root->left);
	PreOrder(root->right);
}
int main(){
	Node *root= new Node(5);
	root->left=new Node (4);
	root->right=new Node (6);
	root->left->left=new Node(3);
	root->right->right=new Node (7);
	PreOrder(root);
	return 0;
}
