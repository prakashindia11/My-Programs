#include "threadClass.h"
#include<iostream>
#include<unistd.h>
using namespace std;
MyThread :: MyThread(void)
{
    pthread_attr_init(&SchedAttr);
}
void *MyThread ::Dosomething(void)
{
    struct sched_param Param;
    int Policy;
    pthread_t th_id = self();
    string Schedule;

    pthread_getschedparam(th_id,&Policy,&Param);
    if(MyPolicy == SCHED_RR)
    {
        Schedule.assign("RR");
    }
    if(MyPolicy == SCHED_FIFO)
    {
        Schedule.assign("FIFO");
    }
    if(MyPolicy == SCHED_OTHER)
    {
        Schedule.assign("OTHER");
    }
    for(int i=0;i<5;i++)
    {
        cout<<"\n Thread #"<<i+1;
        sleep(1);
    }
    cout<<"\n Scheduling Policy:"<<Schedule<<endl;
     cout<<"\n Existing thread:";
     cout<<"\n";
     return NULL;
}
