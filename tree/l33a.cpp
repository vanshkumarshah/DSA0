#include<iostream>
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
class triple{ 
public:
	int numCamera;
	bool isMonitored;
	bool hasCamera;
};
triple helper(TreeNode* root){
	triple t;
	//base case
	if(!root){
		t.numCamera=0;
		t.isMonitored=true;
		t.hasCamera=false;
		return t;
	}

	//recursive case
	triple left=helper(root->left);
	triple right=helper(root->right);

	if(!left.isMonitored ||!right.isMonitored){
		t.numCamera=left.numCamera+right.numCamera+1;
		t.isMonitored=true;
		t.hasCamera=true;
		return t;
	}
	t.numCamera=left.numCamera+right.numCamera;
	t.hasCamera=false;
	t.isMonitored= left.hasCamera||right.hasCamera ? true:false;
	return t;
}
int minCameraCover(TreeNode* root) {
	triple t=helper(root);
	if(root.isMonitored==false)
		return t.numCamera+1;
        
    return t.numCamera;
	}
int main(){

}