
#include<iostream>
#include<cstring>
using namespace std;

class Person
{

protected:
	int iID;
	string sFname,sLanme,sDateOfBirth,sBloodGroup,sAddress;
	float iHeight,iWeight;
	long int iPhoneNo,iInsurenceNo,iDrivingNo;
	Person *Next,*Prev;

public:
static int iCounter;

protected:
	Person()
	{
		Next = NULL;
		Prev = NULL;
		iPhoneNo = 0;
		iCounter++;
		iID = iCounter;

	}

	~Person()
	{
		iCounter--;
	}

friend class PersonManager;

};
int Person::iCounter=0;

class PersonManager
{

	Person *First,*Current,*New1,*SearchedPerson;
	int iPersonCounter;
public:

	PersonManager()
	{
		First=Current=New1=NULL;
		iPersonCounter=0;
	}

	void AddNewPerson()
	{
		if(First==NULL)
		{
			First = new Person();
			cout<<"First Name : ";		cin>>First->sFname;
			cout<<"Last Name : ";		cin>>First->sLanme;
			cout<<"Date Of Birth : ";	cin>>First->sDateOfBirth;
			cout<<"Blood Group : ";		cin>>First->sBloodGroup;
			cout<<"Address : ";			cin>>First->sAddress;
			cout<<"Height : ";			cin>>First->iHeight;
			cout<<"Weight : ";			cin>>First->iWeight;
			cout<<"Phone No : ";		cin>>First->iPhoneNo;
			cout<<"Insurance No : ";	cin>>First->iInsurenceNo;
			cout<<"Driving No: ";		cin>>First->iDrivingNo;

			Current = First;
		}

		else
		{
			New1 = new Person();
			cout<<"First Name : ";		cin>>New1->sFname;
			cout<<"Last Name : ";		cin>>New1->sLanme;
			cout<<"Date Of Birth : ";	cin>>New1->sDateOfBirth;
			cout<<"Blood Group : ";		cin>>New1->sBloodGroup;
			cout<<"Address : ";			cin>>New1->sAddress;
			cout<<"Height : ";			cin>>New1->iHeight;
			cout<<"Weight : ";			cin>>New1->iWeight;
			cout<<"Phone No : ";		cin>>New1->iPhoneNo;
			cout<<"Insurance No : ";	cin>>New1->iInsurenceNo;
			cout<<"Driving No: ";		cin>>New1->iDrivingNo;

			Current->Next = New1;
			New1->Prev = Current;
			New1->Next = NULL;
			Current = New1;

		}
	}

	void SearchPerson(int SearchBy , string sName)
	{

		Person *SearchPt;
		SearchPt = First;
		cout<<"\nID\tName\t\tPhone";
		switch(SearchBy)
		{
			//Search By First Name
			case  1:
						while(SearchPt->Next != NULL)
						{
							if(sName.compare(SearchPt->sFname)==0)
							{
								Display(SearchPt);
								iPersonCounter++;
								SearchedPerson = SearchPt;
							}
							SearchPt = SearchPt->Next;
						}
						if(sName.compare(SearchPt->sFname)==0)
						{
							Display(SearchPt);
							iPersonCounter++;
							SearchedPerson = SearchPt;
						}

			break;

			//Search By Last Name
			case  2:
						while(SearchPt->Next != NULL)
						{
							if(sName.compare(SearchPt->sLanme)==0)
							{
								Display(SearchPt);
							}
							SearchPt = SearchPt->Next;
						}
						if(sName.compare(SearchPt->sLanme)==0)
						{
							Display(SearchPt);
						}
			break;

		}

	}

	void Display(Person *PersonPt)
	{
		cout<<"\n";
		cout<<PersonPt->iID<<"\t";
		cout<<PersonPt->sFname<<"\t";
		cout<<PersonPt->sLanme<<"\t";
		cout<<PersonPt->sDateOfBirth<<"\t";
		cout<<PersonPt->sBloodGroup<<"\t\t";
		cout<<PersonPt->sAddress<<"\t\t";
		cout<<PersonPt->iHeight<<"\t";
		cout<<PersonPt->iWeight<<"\t";
		cout<<PersonPt->iPhoneNo<<"\t";
		cout<<PersonPt->iInsurenceNo<<"\t";
		cout<<PersonPt->iDrivingNo<<"\t";
	}

	void DisplayAll()
	{
		Person *DisplayPt;
		DisplayPt = First;
		cout<<"\nID\tName\t\tDate Of Birth\tBlood Group\tAddress\tHeight\tWeight\tPhone\tInsur.\tDirving\t";
		while(DisplayPt->Next!=NULL)
		{
			Display(DisplayPt);
			DisplayPt = DisplayPt->Next;
		}
		Display(DisplayPt);
		cout<<"\n\nTotal Numbers of Persons : "<<Person::iCounter;
	}

	void DeletePerson()
	{
		Person *DeletePt;
		char sDeleteName[20];
		cout<<"\nEnter first Name Of Person";
		cin>>sDeleteName;
		SearchPerson(1,sDeleteName);
		if(iPersonCounter>0)
		{
			DeletePt = SearchedPerson;
			cout<<"\nPress 1 To Confirm Delete";
			if(DeletePt==First)
			{
				First = DeletePt->Next;
			}
			else if(DeletePt==New1)
			{
				New1 = DeletePt->Prev;
				Current = New1->Prev;
			}
			else
			{
				DeletePt->Prev->Next = DeletePt->Next;
				DeletePt->Next->Prev = DeletePt->Next;
			}
			delete(DeletePt);
		}
		else
		{
			cout<<"\nNot Found";
		}

	}
};


int main()
{

int iChoise,iReprat,iSearchByFName=1,iSearchByLName=2;
char sSearchKeyWord[20];
PersonManager cuManager;
	do
	{
		cout<<"\nPerson Manager";
		cout<<"\n1.Add New Person";
		cout<<"\n2.Search Person By First Name";
		cout<<"\n3.Search Person By Last Name";
		cout<<"\n4.Display All Persons";
		cout<<"\n5. Delete Person";
		cout<<"\nExit\n";
		cin>>iChoise;

		switch(iChoise)
		{
			case 1: cuManager.AddNewPerson();
			break;

			case 2:
					cout<<"\nEnter The First Name Of Person\n";
					cin>>sSearchKeyWord;
					cuManager.SearchPerson(iSearchByFName,sSearchKeyWord);
			break;

			case 3:
				cout<<"\nEnter The Last Name Of Person\n";
					cin>>sSearchKeyWord;
					cuManager.SearchPerson(iSearchByLName,sSearchKeyWord);
			break;

			case 4:
					cuManager.DisplayAll();
			break;

			case 5:	cuManager.DeletePerson();

			break;

		}

		cout<<"\nReturn To Menu? \n 1.Yes 2.No";
		cin>>iReprat;

	}while(iReprat == 1);

return 0;
}
