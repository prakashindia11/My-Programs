#include<iostream>
using namespace std;
#define size 10

class NBSP
{
	public :

	int g[size][size],visit[size],pathlength[size];

	void Input();
	void Path(int);
};

int n,total;

int main()
{
	int i,j;

	NBSP obj;

	obj.Input();

	for(i = 0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			obj.visit[j] = 0;
		}

		total = 0;

		cout<<"\n\nPath from Lane '"<<i+1<<"' : ";
		obj.Path(i);

		obj.pathlength[i] = total;

		cout<<"\nTotal Distance of the path : "<<obj.pathlength[i];
	}

	return 0;
}

void NBSP :: Input()
{
	int i,j;

	cout<<"Enter the number of Lanes : ";
	cin>>n;

	cout<<"\nEnter the distance between Lanes : \n";

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"Lane "<<i+1<<" and "<<j+1<<": ";
			cin>>g[i][j];

			if(g[i][j] == 0)
			{
				g[i][j] = -1;
			}
		}
	}
}


void NBSP :: Path(int i)
{
	int j;

	visit[i] = 1;

	cout<<i+1<<" ";

	for(j=0;j<n;j++)
	{
		if(g[i][j]!=-1 && visit[j] == 0)
		{
			total = total+g[i][j];
			Path(j);
		}
	}
}
