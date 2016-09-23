#include<iostream>
#include<string>
#include<list>
using namespace std;

class PersonDB
{
    public:
    string sName,sDob;
    int iHeight,iWeight;

    PersonDB(){}
};

std::list<PersonDB*> ltPerson;
std::list<PersonDB*>::iterator itPerson;
PersonDB *PersonPtr;
