#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	string var;
	
	var = system("who am i");
	cout<<var;

	var = system("who");
	cout<<"\n"<<var;

	return 0;
}
