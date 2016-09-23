#include <QCoreApplication>
#include<iostream>
using namespace std;


class television
{
    private :

    int model_no,screen_size,price;

    public :

    void initialize()
    {
        model_no = 0;
        screen_size = 0;
        price = 0;
    }

    friend ostream & operator<<(ostream &,television &);
    friend istream & operator>>(istream &,television &);
};

ostream & operator<<(ostream &out,television &t)
{
    out<<"\nYou entered the following details :  : ";
    out<<"\n\nModel Number : "<<t.model_no;
    out<<"\nScreen Size : "<<t.screen_size;
    out<<"\nPrice : $"<<t.price;
    out<<"\n\n";

    return out;

}

istream & operator>>(istream &in,television &t)
{
    cout<<"Enter Model No : ";
    in>>t.model_no;
    cout<<"Enter the screen size (in inches) : ";
    in>>t.screen_size;
    cout<<"Enter the price (in $) : ";
    in>>t.price;
    try
    {
        if(t.screen_size<12 || t.screen_size>70)
        {
            throw 1;
        }

        if(t.price<0 || t.price>5000)
        {
            throw 2;
        }

        if(t.model_no>9999)
        {
            throw 3;
        }
    }
    catch(int n)
    {
        if(n==1)
        {
	    t.initialize();
            cout<<"\nScreen size should be between 12 to 70 inches";
        }
        else if(n==2)
        {
	    t.initialize();
            cout<<"\nPrice should be less than $5000.";
        }
        else if(n==3)
        {
	    t.initialize();
            cout<<"\nModel number should be less than 5 digits.";
        }
    }

    return in;
}

int main()
{
    television t;

    cin>>t;
    cout<<t;

    return 0;
}
