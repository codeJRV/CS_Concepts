#include <iostream>

using namespace std;

struct BSTNode{
	int data;
	BSTNode * left;
	BSTNode * right;
};

BSTNode* GetNewNode(int data)
{
	BSTNode* newNode = new BSTNode();
	newNode->data  = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}


void Insert(BSTNode ** root, int data)
{
	//tree may be empty
	if(*root == NULL)
		*root = GetNewNode(data);
	else if(data <= (*root)->data)
		Insert(&(*root)->left,data);
	else
		Insert(&(*root)->right,data);
	

}

// Inorder ( Left Root Right)
// Preorder (Root, Left , Right)
// Postorder (Left Right Root)

void InOrder (BSTNode *node)
{
	if(!node)
		return;

	InOrder(node->left);
	cout<<node->data<<" ";
	InOrder(node->right);
}

void PreOrder (BSTNode *node)
{
	if(!node)
		return;

	PreOrder(node->left);
	PreOrder(node->right);
	cout<<node->data<<" ";
}

void PostOrder (BSTNode *node)
{
	if(!node)
		return;

	cout<<node->data<<" ";
	PostOrder(node->left);
	PostOrder(node->right);
}


int main(int argc, char const *argv[])
{

	BSTNode* root;
	root =  NULL;	
	Insert(&root,15);
	Insert(&root,25);
	Insert(&root,30);
	Insert(&root,25);
	Insert(&root,3);
	Insert(&root,22);
	Insert(&root,34);

	cout<<"InOrder"<<endl;
	InOrder(root);
	cout<<"PreOrder"<<endl;
	PreOrder(root);
	cout<<"PostOrder"<<endl;
	PostOrder(root);

	return 0;
}
