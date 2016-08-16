#include<iostream.h>
#include<conio.h>
#define size 50

class SS
{
	private:

	int a[size],n;
	int i,j;

	public:

	void input();
	void sort();
	void output();
};

void main()
{
	clrscr();

	SS ss;

	ss.input();
	ss.sort();
	ss.output();

	getch();
}

void SS :: input()
{
	cout<<"How many numbers do you want to enter (Maximum 50) : ";
	cin>>n;

	cout<<"\n\nEnter the numbers : \n";

	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}

}

void SS :: sort()
{
	int gap,temp;

	for(gap = n/2;gap>=1;gap = gap/2)
	{
		for(i = gap;i<n;i++)
		{
			for(j = i-gap;j>=0 && a[j]>a[j+gap];j = j-gap)
			{
				temp = a[j];
				a[j] = a[j+gap];
				a[j+gap] = temp;
			}
		}
	}
}

void SS :: output()
{
	cout<<"\n\nThe ascending order of the entered numbers is as follows : ";

	for(i=0;i<n;i++)
	{
		cout<<"\n"<<a[i];
	}
}