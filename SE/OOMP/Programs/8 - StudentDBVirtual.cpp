
#include<iostream>
using namespace std;

class StudentDB
{
	string sName,sAddress;
	int iAge;
};

class Student
{
public:

	StudentDB *pStudentDB;

	void EnterPersonalInfo()
	{
		cout<<"\nEnter Name";
		cin>>sName;
		cout<<"Enter Address";
		cin>>sAddress;
		cout<<"Enter Age";
		cin>>iAge;
	}

	virtual void EnterAcademicInfo();

};
class UGStudent : Student
{

};
class PGStudent{};
