#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;

};

struct node* newNode(int data)
{
 	node * NewNode = new node;
 	NewNode->left = NULL;
 	NewNode->right = NULL;
 	NewNode->data = data;

 	return(NewNode);
}

int size(struct node* node)
{
	if(node == NULL)
		return 0;
	else
		return(size(node->left) + 1 + size(node->right));

}



int main()
{

	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(4);
	root->left->right = newNode(3);


	cout<<size(root); 
}