#include<iostream>
#include <queue>
using namespace std;
class TreeNode{
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int v){
		this->val=v;
		this->left=NULL;
		this->right=NULL;
	}
};
TreeNode* buildTree(){
	int v;
	cin>>v;
	if(v==-1){
		return NULL;
	}
	TreeNode*root=new TreeNode(v);
	root->left=buildTree();
	root->right=buildTree();
	return root;
}
void levelOrderTraversal(TreeNode*root){
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode* front=q.front();
		q.pop();
		//process front
		cout<<front->val<<" ";

		if(front->left){
			q.push(front->left);
		}if(front->right){
			q.push(front->right);
		}
	}

}
void printlevelOrderTraversal(TreeNode*root){
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		TreeNode* front=q.front();
		q.pop();
		//process front
		if(!front){
					cout<<endl;
					if(!q.empty())
					q.push(NULL);}

					else {if(q.front()==NULL){
										cout<<front->val<<" ";}

		if(front->left){
			q.push(front->left);
		}if(front->right){
			q.push(front->right);
		}
	}}

}
int main(){
	TreeNode*root= buildTree();
	levelOrderTraversal(root);cout<<endl;
	printlevelOrderTraversal(root);
}