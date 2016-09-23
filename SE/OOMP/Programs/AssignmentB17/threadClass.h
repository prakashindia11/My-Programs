#ifndef THREADCLASS_H
#define THREADCLASS_H
#include<iostream>
#include<string>
using namespace std;

class threadClass{
public:
    threadClass();
    virtual ~threadClass();
    void setPolicy(int Policy);
    int run();
    int join();
    pthread_t self();
    virtual void *Dosomething(void) = 0;
    pthread_attr_t SchedAttr;
    struct sched_param SchedParam;
    int MyPolicy;//code for scheduling policy
private:
    pthread_t tid;

};
class MyThread : public threadClass
{
public:
    void *Dosomething(void);
    MyThread(void);
};

#endif // THREADCLASS_H
