#include<iostream>
using namespace std;

typedef struct Node
{
	int data,lthread,rthread;
	struct Node *left,*right;
}node;

int counter = 0,print;
node *root,*newnode;

class TBT
{
	public :

	void create();
	void insert(node*,int);
	void preorder(node*);
	void postorder(node*);
};

int main()
{
	int choice;
	root = NULL;

	TBT obj;

	cout<<"Please select one of the following : ";

	while(1)
	{
		cout<<"\n\n1 Insert \n2 Preorder \n3 Exit";
		cout<<"\nEnter your choice : ";
		cin>>choice;

		switch(choice)
		{
		case 1 :
			obj.create();
			break;

		case 2 :
			print = 0;
			obj.preorder(root);
			break;

		case 3 :
			return 0;
		}
	}

	return 0;
}

void TBT :: create()
{
	int value;

	cout<<"Enter the value :";
	cin>>value;

	if(root == NULL)
	{
		root = new node;
		root->data = value;
		root->left = root;
		root->right = root;
		root->lthread = 0;
		root->rthread = 0;

		counter++;
	}
	else
	{
		insert(root,value);
	}
}

void TBT :: insert(node *root,int value)
{
	if(value<root->data)
	{
		if(root->lthread == 0)
		{
			newnode = new node;
			newnode->data = value;
			newnode->left = root->left;
			newnode->right = root;
			root->left = newnode;

			newnode->lthread = 0;
			newnode->rthread = 0;
			root->lthread = 1;

			counter++;
		}
		else
		{
			insert(root->left,value);
		}
	}
	else
	{
		if(root->rthread == 0)
		{
			newnode = new node;
			newnode->data = value;
			newnode->left = root;
			newnode->right = root->right;
			root->right = newnode;

			newnode->lthread = 0;
			newnode->rthread = 0;
			root->rthread = 1;

			counter++;
		}
		else
		{
			insert(root->right,value);
		}
	}
}

void TBT :: preorder(node *node)
{
	if(root == NULL)
	{
		cout<<"\nThe tree is empty.";
	}
	else
	{
		if(print<counter)
		{
			cout<<node->data<<"\t";

			print++;

			if(node->lthread == 1)
			{
				node = node->left;
				preorder(node);
			}
			else if(node->lthread == 0)
			{
				if(node->rthread == 0)
				{
					node = node->right;
				}

				node = node->right;
				preorder(node);
			}
		}
	}
}

