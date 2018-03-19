struct Node
{

	int data;
	struct Node *next; 
};

static void reverse(struct Node** head)
{

	struct Node* prev = NULL;
	struct Node* current = *head;
	struct Node* next;

	while(current != NULL)
	{

		next = current->next;
		current->next = prev;
		prev  = current;
		current = next;
	}

	*head = prev
}

