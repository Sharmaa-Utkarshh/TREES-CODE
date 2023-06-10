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
void PrintNodesAtDistanceK(struct Node *root,int k){
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<<(root->data)<<endl;
	}
	PrintNodesAtDistanceK(root->left,k-1);
	PrintNodesAtDistanceK(root->right,k-1);
	
}
void LevelOrderTraversal(struct Node *root){
	if(root==NULL){
		return;
	}
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		int sz=q.size();
		for(int i=0;i<sz;i++){
		Node *topp=q.front();
		q.pop();
		cout<<(topp->data)<<" ";
		if(topp->left!=NULL){
			q.push(topp->left);
		}
		if(topp->right!=NULL){
			q.push(topp->right);
		}
		}
		cout<<endl;
	}
}


void ZigZagPrinting(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
   stack<int> s;
    bool reverse = false;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto it = q.front();
            q.pop();
            if (reverse) {
                s.push(it->data);
            } else {
                cout << it->data << " ";
            }
            if (it->left != NULL) {
                q.push(it->left);
            }
            if (it->right != NULL) {
                q.push(it->right);
            }
        }
        if (reverse) {
            while (!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
        }
        reverse = !reverse;
        cout << endl;
    }
}
void ZigZagPrintingUsing2Stacks(struct Node* root){
	if (root == NULL) {
        return;
    }
    std::stack<Node*> s1;
    std::stack<Node*> s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node* top1 = s1.top();
            s1.pop();
            std::cout << top1->data << " ";
            if (top1->left != NULL) {
                s2.push(top1->left);
            }
            if (top1->right != NULL) {
                s2.push(top1->right);
            }
        }
        std::cout << std::endl;
        while (!s2.empty()) {
            Node* top2 = s2.top();
            s2.pop();
            std::cout << top2->data << " ";
            if (top2->right != NULL) {
                s1.push(top2->right);
            }
            if (top2->left != NULL) {
                s1.push(top2->left);
            }
        }
        std::cout << std::endl;
    }
}

int NumberOfNodes(struct Node* root){
	if(root==NULL){
		return 0;
	}	
	return 1+NumberOfNodes(root->left)+NumberOfNodes(root->right);
}

void Maximum(struct Node *root,int &maxi){
	if(root==NULL){
		return ;
	}
	if((root->data)>maxi){
		maxi=root->data;
	}
	Maximum(root->left,maxi);
	Maximum(root->right,maxi);
}
void LeftView(struct Node *root){
	if(root==NULL){
		return;
	}
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		int sz=q.size();
		for(int i=0;i<sz;i++){
		Node *topp=q.front();
		q.pop();
		if(i==0){
		cout<<(topp->data)<<" ";
		}
		if(topp->left!=NULL){
			q.push(topp->left);
		}
		if(topp->right!=NULL){
			q.push(topp->right);
		}
		}
		cout<<endl;
	}
}
void RightView(struct Node *root){
	if(root==NULL){
		return;
	}
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		int sz=q.size();
		for(int i=0;i<sz;i++){
		Node *topp=q.front();
		q.pop();
		if(i==sz-1){
		cout<<(topp->data)<<" ";
		}
		if(topp->left!=NULL){
			q.push(topp->left);
		}
		if(topp->right!=NULL){
			q.push(topp->right);
		}
		}
		cout<<endl;
	}
}
bool ChildrenSumProp(struct Node* root){
	if(root==NULL){
		return true;
	}
	if(root->left==NULL && root->right==NULL){
		return true;
	}
	int sum=0;
	if(root->left!=NULL){
		sum+=root->left->data;
	}
	if(root->right!=NULL){
		sum+=root->right->data;
	}
	return (root->data==sum && ChildrenSumProp(root->left) && ChildrenSumProp(root->right));
}

int height(struct Node* root){
	if(root==NULL){
		return 0;
	}
	return 1+max(height(root->left),height(root->right));
}
int BalancedTree(struct Node* root){
	if(root==NULL){
		return 0;
	}
	int lh=BalancedTree(root->left);
	int rh=BalancedTree(root->right);
	if(lh==-1 || rh==-1){
		return -1;
	}
	if(abs(lh-rh)>1){
		return -1;
	}
	return 1+max(BalancedTree(root->left),BalancedTree(root->right));
}
int diameter(struct Node* root,int &ans){
	if(root==NULL){
		return  0;
	}
	int lh=diameter(root->left,ans);
	int rh=diameter(root->right,ans);
	ans=max(ans,1+lh+rh);
	return 1+max(lh,rh);
}
int main(){
	Node *root= new Node(5);
	root->left=new Node (5);
	root->right=new Node (5);
	root->left->left=new Node(5);
	root->right->right=new Node (5);
	// PreOrder(root);
	// PrintNodesAtDistanceK(root,2);
	// LevelOrderTraversal(root);
	// ZigZagPrinting(root);
	// ZigZagPrintingUsing2Stacks(root);
	// cout<<NumberOfNodes(root)<<endl;
	// int maxi=INT_MIN;
	// Maximum(root,maxi);
	// cout<<maxi<<endl;
	// LeftView(root);
	// RightView(root);
	// cout<<height(root)<<endl;
	// cout<<BalancedTree(root)<<endl;
	int ans=0;
	int d=diameter(root,ans);
	cout<<ans<<endl;
	return 0;
}}
