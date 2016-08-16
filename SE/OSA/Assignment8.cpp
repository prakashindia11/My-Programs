#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
	int pid;
	
	pid = fork();

	if(pid<0)
	{
		cout<<"No process is created\n";
	}
	else if(pid == 0)
	{
		cout<<"Child process id : "<<pid<<"\n";
	}
	else
	{
		cout<<"Parent process id : "<<pid<<"\n";
	}
	
	return 0;
}
