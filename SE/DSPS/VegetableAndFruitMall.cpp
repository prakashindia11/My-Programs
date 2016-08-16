#include<iostream>
#include<string.h>
#include<sstream>
using namespace std;

#define size 20

typedef struct Node
{
	char name[size];
	int quantity;
}node;

class Mall
{
	private :

	int front,rear,counter;
	node queue[size];

	public :

	void Getdata();
	void Display();

	Mall()
	{
		front = rear = -1;
		counter = 0;
	}
};

int main()
{
	int choice;

	Mall obj;

	cout<<"Please select one of the following options : ";

	while(1)
	{
		cout<<"\n\n1 Enter Data \n2 Display Data \n3 Exit";
		cout<<"\nEnter your choice : ";
		cin>>choice;

		switch(choice)
		{
		case 1 :
			obj.Getdata();
			break;

		case 2 :
			obj.Display();
			break;

		case 3 :
			return 0;

		default :
			cout<<"\nPlease select a valid option.";
		}
	}

	return 0;
}

void Mall :: Getdata()
{
	int sale,i;
	char vname[size];

	cout<<"Enter the name of vegetable : ";
	cin>>vname;
	cout<<"Enter the sale quantity of '"<<vname<<"' in KG : ";
	cin>>sale;

	if(front == -1)
	{
		front++;
		rear++;
	}

	i = rear;

	while(i>=0 && sale>queue[i].quantity) // For sorting in descending order
	{
		queue[i+1].quantity = queue[i].quantity;
		strcpy(queue[i+1].name,queue[i].name);

		i--;
	} // After coming out of the loop 'i' will be one position behind the empty slot. Hence we have to increment i

	i++;

	queue[i].quantity = sale;
	strcpy(queue[i].name,vname);

	rear++;
}

void Mall :: Display()
{
	if(front == rear)
	{
		cout<<"\nThe data list is empty.";
	}
	else
	{
		cout<<"\nVegetable Name : "<<queue[front].name;
		cout<<"\nQuantity sold : "<<queue[front].quantity<<" KG ";

		front++;
	}
}
