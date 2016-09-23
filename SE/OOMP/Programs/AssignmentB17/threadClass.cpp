#include "threadClass.h"
threadClass:: threadClass()
{
    pthread_attr_init(&SchedAttr);
    pthread_attr_setinheritsched(&SchedAttr,PTHREAD_EXPLICIT_SCHED);
    MyPolicy = SCHED_OTHER;//default scheduling policy

}
threadClass::~threadClass()
{

}
void threadClass :: setPolicy(int Policy)
{
    if(Policy ==1)
    {
        pthread_attr_setschedpolicy(&SchedAttr,SCHED_RR);
        pthread_attr_getschedpolicy(&SchedAttr,&MyPolicy);
    }
    if(Policy ==2)
    {
        pthread_attr_setschedpolicy(&SchedAttr,SCHED_FIFO);
        pthread_attr_getschedpolicy(&SchedAttr,&MyPolicy);
    }
}
static void *function(void *arg);
int threadClass::run()
{
    int result = pthread_create(&tid,NULL,function,this);
    return result;
}
int threadClass :: join()
{
    return(pthread_join(tid,NULL));
}
pthread_t threadClass::self()
{
    return tid;
}
static void *function(void *arg)
{
    return ((threadClass*)arg)->Dosomething();
}
