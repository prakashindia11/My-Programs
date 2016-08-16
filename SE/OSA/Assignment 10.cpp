#include<iostream>
using namespace std;
#include<pwd.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{

	struct passwd *comp;

	comp = getpwuid(getuid());

	cout<<comp->pw_name<<"\n";
	cout<<comp->pw_passwd<<"\n";
	cout<<comp->pw_uid<<"\n";
	cout<<comp->pw_gid<<"\n";
	cout<<comp->pw_gecos<<"\n";
	cout<<comp->pw_dir<<"\n";
	cout<<comp->pw_shell<<"\n";	

	return 0;
}
