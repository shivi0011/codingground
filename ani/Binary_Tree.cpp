#include <iostream>
using namespace std;

struct tree{

	int data;
	struct tree *left, *right;
};

int i =0;
struct tree* insert(int data, struct tree **root)
{
	
	if(*root == NULL)
	{
		struct tree * temp = (struct tree *) malloc(sizeof(struct tree));
	
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		*root = temp;
		return *root;
	}

	if(data < (*root)->data)
	{
		(*root)->left =insert(data, &(*root)->left);
	}

	if(data > (*root)->data)
	{
		(*root)->right=  insert(data, &(*root)->right);
	}
	return *root;

}


void Inorder(struct tree * root)
{
	if(root != NULL)
	{
		Inorder(root->left);
		cout<< root->data << "  ";
		Inorder(root->right);
	}
}



void mirror(struct tree ** root)
{
	if(*root == NULL)
		return;
	else
	{

		mirror(&(*root)->left);
		mirror(&(*root)->right);

		struct tree *temp;

		temp = (*root)->left;
		 (*root)->left =  (*root)->right;
		  (*root)->right = temp;
		  return;
	}
}

int mainff()
{
	struct tree *root = NULL;
	insert(15, &root);
	insert(10, &root);
	insert(16, &root);
	insert(19, &root);
	insert(2, &root);
	Inorder(root);
	mirror(&root);
	cout<<"After Mirror" <<endl;
	Inorder(root);
	return 0;
}


 
/* Given a binary tree, print its nodes in reverse level order */
bool isIsomorphic(tree* n1, tree *n2)
{
 // Both roots are NULL, trees isomorphic by definition
 if (n1 == NULL && n2 == NULL)
    return true;
 
 // Exactly one of the n1 and n2 is NULL, trees not isomorphic
 if (n1 == NULL || n2 == NULL)
    return false;
 
 if (n1->data != n2->data)
    return false;
 
 // There are two possible cases for n1 and n2 to be isomorphic
 // Case 1: The subtrees rooted at these nodes have NOT been "Flipped".
 // Both of these subtrees have to be isomorphic, hence the &&
 // Case 2: The subtrees rooted at these nodes have been "Flipped"
 return
 (isIsomorphic(n1->left,n2->left) && isIsomorphic(n1->right,n2->right))||
 (isIsomorphic(n1->left,n2->right) && isIsomorphic(n1->right,n2->left));
}



