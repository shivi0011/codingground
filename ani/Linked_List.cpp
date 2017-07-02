#include <iostream>
using namespace std;

static int i = 0;
struct node
{
	int data;
	struct node *next;
};
struct node *root= NULL;

void insert(int data, struct node** root)
{
	struct node *temp = (struct node *) malloc(sizeof(node));
	if(temp != NULL)
	{
		temp->data = data;
		temp->next = *root;
	}

	*root = temp;
}

void reverse(struct node **root)
{
	struct node *current = *root;
	struct node *prev =NULL, *next =NULL;

	while(current != NULL)
	{
		next = current->next;
		current->next =prev;
		prev =current;
		current = next;
	}

	*root = prev;
}


void traverse(struct node*root)
{
	struct node *temp = root;
	while(temp!=NULL)
	{
		cout<<temp->data <<endl;
		temp = temp->next;
	}
}

void delete_(int ele, struct node **root)
{
	struct node *temp = *root ,*prev = NULL;

	if(temp != NULL && temp->data == ele)
	{
		*root = temp->next;
		free(temp);
		return;
	}

	while(temp != NULL && temp->data != ele)
	{
		prev = temp;
		temp= temp->next;
	}

	if(temp != NULL)
	{
		prev->next = temp->next;
		free(temp);
	}
}


void delete_at_mid(struct node **root)
{
	struct node *temp = *root, *forward =NULL ,* prev;


	if(temp->next == NULL)
	{
		free(temp);
		return;
	}
	else
	{
		forward = temp->next;
		while(forward->next != NULL)
		{
			prev = temp;
			forward = forward->next->next;
			temp = temp->next;
			
		}

		cout<< "Middle Element " << temp->data;

		prev->next = temp->next;
		free(temp);
	}


}

void delete_at_pos(int pos, struct node **root)
{
	struct node *temp = *root ,*prev;
	if(pos == 1)
	{
		*root= temp->next;
		free(temp);
		return;
	}
	int i = 1;
	while(temp!= NULL && pos != i)
	{
		prev= temp;
		temp = temp->next;
		i++;
	}

	if(temp != NULL)
	{
		prev->next = temp->next;
		free(temp);
	}
}


void swap_nodes(int x, int y, struct node **root)
{


	if(x == y)
		return;
	struct node *temp= NULL, *prev_first = NULL,*second_prev = NULL;
	struct node *first = *root , *second = *root;
	while(first != NULL && x != first->data)
	{
		prev_first = first;
		first = first->next;
	}

	while(second != NULL && y != second->data)
	{
		second_prev = second;
		second = second->next;
	}



	if( first == NULL || second == NULL)
		return;

	if(prev_first != NULL)
		prev_first->next = second;
	else
		*root = second;

	if(second_prev != NULL)
		second_prev->next = first;
	else
		*root = first;
	
	temp = first->next;
	first->next = second->next;
	second->next = temp;

}


  // Search for y (keep track of prevY and CurrY
/* Function to swap nodes x and y in linked list by
   changing links */
void swapNodes(struct node **head_ref, int x, int y)
{
   // Nothing to do if x and y are same
   if (x == y) return;
 
   // Search for x (keep track of prevX and CurrX
   struct node *prevX = NULL, *currX = *head_ref;
   while (currX && currX->data != x)
   {
       prevX = currX;
       currX = currX->next;
   }
 
   // Search for y (keep track of prevY and CurrY
   struct node *prevY = NULL, *currY = *head_ref;
   while (currY && currY->data != y)
   {
       prevY = currY;
       currY = currY->next;
   }
 
   // If either x or y is not present, nothing to do
   if (currX == NULL || currY == NULL)
       return;
 
   // If x is not head of linked list
   if (prevX != NULL)
       prevX->next = currY;
   else // Else make y as new head
       *head_ref = currY;  
 
   // If y is not head of linked list
   if (prevY != NULL)
       prevY->next = currX;
   else  // Else make x as new head
       *head_ref = currX;
 
   // Swap next pointers
   struct node *temp = currY->next;
   currY->next = currX->next;
   currX->next  = temp;
}
int mainrrrhb()
{
	insert(5, &root);
	insert(9, &root);

	insert(3, &root);

	insert(8, &root);

	insert(7, &root);

	insert(2, &root);
	traverse(root);

	//reverse(&root);
	//delete_(5, &root);

	//delete_at_pos(7, &root);
	//delete_at_mid(&root);

	swap_nodes(5,2,&root);

	//swapNodes(&root,9,7);
	cout<<"After Deletion" <<endl;
	traverse(root);
	return 0;
}

