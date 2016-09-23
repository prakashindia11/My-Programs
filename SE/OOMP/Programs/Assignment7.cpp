#include<iostream>
using namespace std;
#define size 3

template <class T>
class matrix
{
	private : 

	T a[size][size];

	public :

	void Getdata();
	void Display();
	void Add(matrix <T>,matrix <T>);
	void Sub(matrix <T>,matrix <T>);
	void Mul(matrix <T>,matrix <T>);
};

template <class T>
void matrix <T> :: Getdata()
{
	int i,j;

	cout<<"\nEnter the matrix data : \n";

	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			cout<<"M"<<i+1<<j+1<<" : "; 
			cin>>a[i][j]; 
		}
	}			
}

template <class T>
void matrix <T> :: Display()
{
	int i,j;

	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{ 
			cout<<a[i][j]<<"\t"; 
		}
		
		cout<<"\n";
	}
}

template <class T>
void matrix <T> :: Add(matrix <T> m1,matrix <T> m2)
{
	int i,j;
	
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			a[i][j]=m1.a[i][j]+m2.a[i][j];
		}
	}
}

template <class T>
void matrix <T> :: Sub(matrix <T> m1,matrix <T> m2)
{
	int i,j;
	
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			a[i][j]=m1.a[i][j]-m2.a[i][j];
		}
	}
}

template <class T>
void matrix <T> :: Mul(matrix <T> m1,matrix <T> m2)
{
	int i,j,k;

	for(i=0;i<size;i++)
	{	
		a[i][j]=0;		
			
		for(j=0;j<size;j++)
		{
			for(k=0;k<size;k++)
			{
				a[i][j]=a[i][j]+m1.a[i][k]*m2.a[k][j];
			}
		}
	}	
}

int main()
{
	int choice;
	matrix <int> m1,m2,m3;

	cout<<"\nMatrix 1";
	m1.Getdata();
	
	cout<<"\nMatrix 2";
	m2.Getdata();

	cout<<"\nMatrix 1 : "<<endl;
	m1.Display();
	
	cout<<"\nMatrix 2 : "<<endl;
	m2.Display();

	cout<<"\nSelect one of the following options : ";
	
	while(1)
	{
		cout<<"\n\n1 Addition \n2 Subtraction \n3 Multiplication \n4 Exit";
		cout<<"\nEnter your choice : ";
		cin>>choice;

		switch(choice)
		{
		case 1 :
			m3.Add(m1,m2);
			cout<<"\nAddition : "<<endl;
			m3.Display();
			break;
		case 2 :
			m3.Sub(m1,m2);
			cout<<"\nSubtraction : "<<endl;
			m3.Display();
			break;
		case 3 :
			m3.Mul(m1,m2);
			cout<<"\nMultiplication : "<<endl;
			m3.Display();
			break;
		case 4 :
			return 0;
		default : cout<<"Enter proper option.";
		}	
	}

	return 0;
}
