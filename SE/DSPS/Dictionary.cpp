#include<iostream>
#include<sstream>
#include<string.h>
using namespace std;


typedef struct Node
{
	char word[20];
	string meaning;
	struct Node *left,*right;

}node;

node *root,*newnode;

class Dictionary
{
	public :

	void create();
	void insert(node*,node*);
	void display(node*);
};

int main()
{
	int choice;
	root = NULL;

	Dictionary obj;

	cout<<"Please select one of the following options : ";

	while(1)
	{
		cout<<"\n\n1 Insert word \n2 Display words \n3 Exit";
		cout<<"\nEnter your choice : ";
		cin>>choice;

		switch(choice)
		{
		case 1 :
			obj.create();
			break;

		case 2 :
			obj.display(root);
			break;

		case 3 :
			return 0;

		default : cout<<"\nPlease select a proper choice.";
				  break;
		}
	}
}

void Dictionary :: create()
{
	newnode = new node;

	cout<<"Enter word : ";
	cin>>newnode->word;

	cin.ignore();

	cout<<"Enter the meaning of '"<<newnode->word<<"' : ";
	getline(cin,newnode->meaning);

	newnode->left = NULL;
	newnode->right = NULL;

	if(root == NULL)
	{
		root = newnode;
	}
	else
	{
		insert(root,newnode);
	}
}

void Dictionary :: insert(node *root,node *newnode)
{
	int c;

	c = strcmp(newnode->word,root->word);

	if(c<0)
	{
		if(root->left == NULL)
		{
			root->left = newnode;
		}
		else
		{
			insert(root->left,newnode);
		}
	}
	else
	{
		if(root->right == NULL)
		{
			root->right = newnode;
		}
		else
		{
			insert(root->right,newnode);
		}
	}
}

void Dictionary :: display(node *node)
{
	if(root == NULL)
	{
		cout<<"\nThe dictionary is empty.";
	}
	else
	{
		if(node == NULL)
		{
			return;
		}
		else
		{
			display(node->left);
			cout<<"\n"<<node->word<<" : "<<node->meaning;
			display(node->right);
		}
	}
}
