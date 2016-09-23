#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include"threadClass.h"
using namespace std;
int main(int argc, char** argv)
{
     MyThread * thread1 =new MyThread();
     MyThread * thread2 =new MyThread();
     MyThread * thread3 =new MyThread();
     thread1->setPolicy(1);
     thread2->setPolicy(2);
     thread3->setPolicy(3);
     thread1->run();
     thread1->join();
     thread2->run();
     thread2->join();
     thread3->run();
     thread3->join();
     cout<<"Executin of main is over\n";
     exit (0);
}
