#include<iostream>
#include<sys/sysinfo.h>
using namespace std;

int main()
{
	struct sysinfo myinfo;

	sysinfo(&myinfo);
	cout<<"Total RAM : "<<(myinfo.totalram)/(1024*1024)<<" MB \n";
	cout<<"Free RAM : "<<(myinfo.freeram)/(1024*1024)<<" MB \n";

	return 0;

}
