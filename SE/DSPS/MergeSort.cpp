#include<iostream>
using namespace std;

class MS
{
	public :

	int n;

	MS()
	{
		n = 0;
	}

	void Divide(int[],int,int);
	void Merge(int[],int,int,int);
};

int main()
{
	int n;
	int i;

	MS obj;

	cout<<"How many values do you want to enter : ";
	cin>>n;

	cout<<"\nEnter the values : ";

	int a[n];

	for(i=0;i<n;i++)
	{
		cout<<"\n";
		cout<<"Number "<<i+1<<" : ";
		cin>>a[i];
	}

	obj.Divide(a,0,n-1);

	// Program for printing the sorted values

	cout<<"\n\nThe ascending order of the values is as follows :";

	for(i=0;i<n;i++)
	{
		cout<<"\n"<<a[i];
	}

	return 0;
}

void MS :: Divide(int a[],int low,int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;

		Divide(a,low,mid);
		Divide(a,mid+1,high);
		Merge(a,low,mid,high);
	}
}

void MS :: Merge(int a[],int low,int mid,int high)
{
	int i=0,k=0,j=mid+1,c[n];

	// Program for sorting the numbers

	while(i<mid && j<=high)
	{
		if(a[i]<a[j])
		{
			c[k] = a[i];

			i++;
			k++;
		}
		else
		{
			c[k] = a[j];

			j++;
			k++;
		}
	}

	// Program for copying the values

	while(i<=mid)
	{
		c[k] = a[i];

		i++;
		k++;	
	}

	while(j<=high)
	{
		c[k] = a[j];

		j++;
		k++;
	}

	for(i=0;i<k;i++)
	{
		a[i] = c[i];
	}
}
