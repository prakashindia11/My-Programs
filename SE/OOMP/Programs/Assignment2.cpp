#include<iostream>
#include<string.h>
using namespace std;
#define max 20

class node
{
	public :
	char *title,*author,*publisher;
	float price;
	int quantity;
	node *next;

	node()
	{
		title = new char[max];
		author = new char[max];
		publisher = new char[max];
	}
};

class book
{
	public :
	node *head;

	void Input();
	void Display();
	void Search();

	book(){head = NULL;}
};

int main()
{
	book obj;
	int choice;

	cout<<"Select one of the options : ";
	while(1)
	{
		cout<<"\n\n1 Enter data of book \n2 Display data of books \n3 Search book \n4 Exit";
		cout<<"\nEnter your choice : ";
		cin>>choice;

		switch(choice)
		{
		case 1:
			obj.Input();
			break;
		case 2:
			cout<<"\nTitle  Author  Publisher  Price  Stock";
			obj.Display();
			break;
		case 3:
			obj.Search();
			break;
		case 4:
			return 0;
		default :
			cout<<"\nSelect a proper choice.";
		}
	}
	return 0;
}

void book:: Input()
{
	node *newnode,*temp;
	newnode = new node;

	cout<<"\nTitle of Book : ";
	cin>>newnode->title;
	cout<<"Author of Book : ";
	cin>>newnode->author;
	cout<<"Publisher of Book : ";
	cin>>newnode->publisher;
	cout<<"Price of Book : ";
	cin>>newnode->price;
	cout<<"Stock of Book : ";
	cin>>newnode->quantity;

	if(head == NULL)
	{ head = newnode;}
	else
	{
		temp = head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

void book:: Display()
{
	node *dispnode;

	if(head == NULL)
	{cout<<"\nThere are no records to display.";}
	else
	{
		dispnode = head;
		while(dispnode!=NULL)
		{
			cout<<"\n"<<dispnode->title<<" \t "<<dispnode->author<<" \t "<<dispnode->publisher<<" \t "<<dispnode->price<<" \t "<<dispnode->quantity;
			dispnode = dispnode->next;
		}
	}
}

void book:: Search()
{
	node *snode = head;
	char stitle[max],sauthor[max];
	int a,t,squantity,c = 0;
	float total;

	cout<<"\nEnter name of book : ";
	cin>>stitle;
	cout<<"Enter name of author : ";
	cin>>sauthor;

	while(snode!=NULL)
	{
		t = strcmp(stitle,snode->title); a = strcmp(sauthor,snode->author);

		if(a==0 && t==0)
		{
			cout<<"\nBook Name : "<<snode->title;
			cout<<"\nBook Author : "<<snode->author;
			cout<<"\nBook Publisher : "<<snode->publisher;
			cout<<"\nAvailable Copies : "<<snode->quantity;

			cout<<"\nEnter the number of copies you want :";
			cin>>squantity;

			if(squantity<=snode->quantity)
			{
				total = squantity*snode->price;
				cout<<"Total price : Rs "<<total;
				snode->quantity = snode->quantity-squantity;
			}
			else
			{cout<<"\nRequired number of books are not avilable.";}

			c = 1;
			break;
		}
		snode = snode->next;
	}

	if(c==0){cout<<"\nThe required book is not available.";}
}
