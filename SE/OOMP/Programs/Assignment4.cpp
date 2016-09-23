#include<iostream>
#include<math.h>
using namespace std;

class complex
{
	float real,img; 

	public :

	complex()
	{	
		real = 0;
		img = 0;	
	}

	complex(float a,float b)
	{
		real = a;
		img = b;
	}

	complex operator+(complex c2)
	{
		complex ans;

		ans.real = real+c2.real;
		ans.img = img +c2.img;

		return ans;
	}

	complex operator-(complex c2)
	{
		complex ans;

		ans.real = real-c2.real;
		ans.img = img -c2.img;

		return ans;
	}

	friend complex operator*(complex c1,complex c2)
	{
		complex ans;

		ans.real = c1.real*c2.real-c1.img*c2.img;
		ans.img = c1.real*c2.img+c1.img*c2.real;

		return ans;
	}

	friend complex operator/(complex c1,complex c2)
	{
		complex ans;

		ans.real = ((c1.real*c2.real)+(c1.img*c2.img))/(pow(c2.real,2)+pow(c2.img,2));
		ans.img = (-(c1.real*c2.img)+(c1.img*c2.real))/(pow(c2.real,2)+pow(c2.img,2));

		return ans;
	}

	void Display();
};

int main()
{
	float a1,b1,a2,b2;
	int choice;
	complex c1,c2,c3;

	cout<<"Enter Real part for 1st Number : "; cin>>a1;
	cout<<"Enter Imaginary part for 1st Number : "; cin>>b1;
	cout<<"\nEnter Real part for 2nd Number : "; cin>>a2;
	cout<<"Enter Imaginary part for 2nd Number : "; cin>>b2;
	while(1)
	{
		cout<<"\nSelect the operation to be performed : ";
		cout<<"\n1 Addition \n2 Subtraction \n3 Multiplication \n4 Division \n5 Exit";
		cout<<"\nEnter your choice : "; cin>>choice;
	
		c1 = complex(a1,b1);
		c2 = complex(a2,b2);

		switch(choice)
		{
		case 1 :
			c3 = c1+c2;
			break;
		case 2 :
			c3 = c1-c2;
			break;
		case 3 :
			c3 = c1*c2;
			break;
		case 4 :
			c3 = c1/c2;
			break;
		case 5 :
			return 0;
		default : 
			cout<<"\nSelect proper choice.";
			break;
		}

		c3.Display();
	}

	c3.Display();
	
	return 0;
}

void complex :: Display()
{
	cout<<"\nAnswer = "<<real<<" + "<<img<<"i\n";	
}
