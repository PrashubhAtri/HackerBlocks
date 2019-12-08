#include <iostream>
#include <algorithm>
using namespace std;
class node{
public:
	int data;
	node* right;
	node* left;

	node(int data){
		this->data = data;
		this->left = NULL;
		this->right =NULL;
	}
};
node* buildBST(int arr[],int start,int end){
	if(start>end){
		return NULL;
	}
	int mid = start + (end-start)/2;
	node* root = new node(arr[mid]);
	root->left = buildBST(arr,start,mid-1);
	root->right = buildBST(arr,mid+1,end);
	return root;
}
void displayPreorder(node*root){
	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";
	displayPreorder(root->left);
	displayPreorder(root->right);
}
int main(){
	int t;
	cin>>t;
	for(int k=0;k<t;k++){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		node* root = buildBST(arr,0,n-1);
		displayPreorder(root);
		cout<<endl;
	}
	return 0;
}