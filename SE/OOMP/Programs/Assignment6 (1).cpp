#include<iostream>
#include<string.h>
#include<iomanip>
#include<fstream>
using namespace std;

class person
{
	private :

	char *name,*dob,*bg,*add;
	float height,weight,ipn,tn,dln;

	public :

	static int count;

	person()
	{
		name = new char[20];
		dob = new char[11];
		bg = new char[3];
		add = new char[50];
		height = 0; weight = 0;
		ipn = 0; tn = 0; dln = 0;
	}

	static void total()
	{
		cout<<"\n\nTotal number of records : "<<count;
	}

	void Input();
	void Display();
	int Delete(person *);
};

int person ::count = 0;

int main()
{
	int choice,i,n=1;
	person obj[50],del;
	fstream file;
	file.open("person.dat",ios::in|ios::app);

	cout<<"Select one of the following options : ";

	while(1)
	{
		cout<<"\n\n1 Enter data of person \n2 Display records \n3 Delete a record \n4 Exit";
		cout<<"\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
		case 1 :
			obj[n].Input();
			file.write((char*)&obj[n],sizeof(obj[n]));
			n++;

			break;
		case 2 :
			file.seekg(0);

			cout<<"\nName \t DoB \t  Blood Group \t Address  \t Height (cm)  \t Weight (KG) \t Policy Number \t Telephone Number \t License Number";
			for(i=1;i<=del.count;i++)
			{
				file.read((char *) & obj[i],sizeof(obj[i]));
				obj[i].Display();
			}
			person ::total();
			break;
		case 3 :
			file.seekg(0);	
			file.read((char *) & obj, sizeof(obj));
			n = del.Delete(obj);
			break;
		case 4 :
			return 0;

		default :
			cout<<"\nError! Select a proper choice.";
		}
	}

	return 0;
}

void person ::Input()
{
	cout<<"\nName : ";
	cin>>this->name;
	cout<<"Date of Birth (dd/mm/yyyy) : ";
	cin>>this->dob;
	cout<<"Blood Group : ";
	cin>>this->bg;
	cout<<"Address : ";
	cin>>this->add;
	cout<<"Height (cm) : ";
	cin>>this->height;
	cout<<"Weight (KG) : ";
	cin>>this->weight;
	cout<<"Insurance Policy Number : ";
	cin>>this->ipn;
	cout<<"Telephone Number : ";
	cin>>this->tn;
	cout<<"Driving License Number : ";
	cin>>this->dln;

	count++;
}

void person ::Display()
{
	cout<<"\n"<<this->name<<setw(10)<<this->dob<<setw(10)<<this->bg<<setw(10)<<this->add<<setw(10)<<this->height<<setw(10)<<this->weight<<setw(10)<<this->ipn<<setw(10)<<this->tn<<setw(10)<<this->dln;
}

int person ::Delete(person *obj)
{
	char sname[20];
	float stn;
	int n,i;

	cout<<"\nEnter the Name to be searched : ";
	cin>>sname;
	cout<<"Enter the Telephone Number of "<<sname<<" : ";
	cin>>stn;
	for(i=1;i<=count;i++)
	{
		n = strcmp(sname,obj[i].name);

		if(n==0 && stn==obj[i].tn)
		{
			delete obj[i].name;
			delete obj[i].dob;
			delete obj[i].bg;
			delete obj[i].add;

			cout<<"\nThe record is deleted successfully.";

			while(i<=count)
			{
				obj[i]=obj[i+1];
				i++;
			}
			count--;
			break;
		}
	}
	return i;
}
