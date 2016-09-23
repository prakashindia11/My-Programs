#include<iostream>
#include<string.h>
using namespace std;
#define SIZE 20

class stringclass
{

	public : 

	char str[SIZE];

	void operator==(stringclass s2)
	{
		if(strcmp(str,s2.str)==0)
		{
			cout<<"\nThe strings are equal.\n";
		}
		else
		{cout<<"\nThe strings are not equal.\n";}
	}

	void operator=(stringclass s2)
	{ 
		strcpy(str,s2.str);
		cout<<"\nString copy : "<<str<<"\n";
 	}

	void operator+(stringclass s2)
	{
		strcat(str,s2.str);
		cout<<"\nString concatenation :"<<str<<"\n";
	}

	friend void operator<<(ostream &,stringclass &);

	void operator>>(stringclass s2)
	{
		char temp;
		int i,j;
		
		for(i=0,j=strlen(str)-1;i<j;i++,j--)
		{	
			temp=str[i];
			str[i]=str[j];
			str[j]=temp;
		}

		for(i=0,j=strlen(s2.str)-1;i<j;i++,j--)
		{	
			temp=s2.str[i];
			s2.str[i]=s2.str[j];
			s2.str[j]=temp;
		}
		
		cout<<"\n1st String : "<<str;
		cout<<"\n2nd String : "<<s2.str<<"\n";
	}

	void palindrome()
	{
		int i,j,c=0;
		
		for(i=0,j=strlen(str)-1;i<=j;i++,j--)
		{	
			if(str[i]!=str[j])
			{
				cout<<"\nThe "<<str<<" is not a palindrome.\n";
				c=1;
				break;
			}
		}

		if(c==0)
		{ cout<<"\nThe "<<str<<" is a palindrome.\n";}
	}
	
};


void operator<<(ostream &out,stringclass &s)
{
	out<<s.str<<"\n";
}

int main()
{
	int choice;
	stringclass s1,s2;

	cout<<"\nEnter 1st String : "; cin>>s1.str;
	cout<<"Enter 2nd String : "; cin>>s2.str;

	while(1)
	{
		cout<<"\nSelect the operation to be performed : ";
		cout<<"\n1 Equality (==) \n2 String Copy (=) \n3 Conctenation (+) \n4 Display (<<) \n5 Reverse String (>>) \n6 Palindrome Check \n7 Exit";
		cout<<"\nEnter your choice : "; cin>>choice;

		switch(choice)
		{
		case 1 :
			s1==s2;
			break;
		case 2 :
			s1=s2;
			break;
		case 3 :
			s1+s2;
			break;
		case 4 :
			cout<<s1;
			cout<<s2;
			break;
		case 5 : 
			s1>>s2;
			break;
		case 6 :
			s1.palindrome();
			s2.palindrome();
			break;
		case 7 : 
			return 0;
			break;
		default : 
			cout<<"\nSelect proper choice.";
			break;
		}
	}

	return 0;
}
