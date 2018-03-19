#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node * next;
};

void pairWiseSwap(Node *head)
{
	Node* temp = head;

	while (temp && temp->next)
	{
		int a;
		a = temp->data;
		temp->data = temp->next->data ;
		temp->next->data = a;

		temp = temp->next->next;
	}
}

int main(int argc, char const *argv[])
{
	Node * head ;
	head->data = 1;

	return 0;
}