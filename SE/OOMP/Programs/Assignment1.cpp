#include<iostream>
using namespace std;

class weather
{
	private :

	int high_temp,low_temp,amount_rain,amount_snow;

	public :

	int day_of_month;

	void Input(int);
	void Display();
	void Average(weather *);

	weather()
	{
		day_of_month = 99;
		high_temp = 999;
		low_temp = -999;
		amount_rain = 0;
		amount_snow = 0;
	}
};

int main()
{
	weather obj[12][31],avg,t[31];

	int day,month,i,choice;

	cout<<"Select one of the following option : ";

	while(1)
	{
		cout<<"\n\n1 Enter Data";
		cout<<"\n2 Display Data";
		cout<<"\n3 Exit";
		cout<<"\nEnter your choice : ";
		cin>>choice;

		switch(choice)
		{
		case 1 :
			cout<<"\nEnter month : ";
			cin>>month;

			cout<<"Enter day of month : ";
			cin>>day;

			if(month<=12 && day<=31)
			{
				obj[month][day].Input(day);
			}
			else
			{
				cout<<"\nEnter proper month and day.";
			}

			break;

		case 2 :
			cout<<"\nSelect a month : ";
			cin>>month;

			cout<<"\nMonth : "<<month;

			cout<<"\nDay  High Temp  Low Temp  Rain  Snow";

			if(month<=12)
			{

				if(month%2==1 || month == 8)
				{
					for(i = 1;i<=31;i++)
					{
						obj[month][i].Display();
						t[i] = obj[month][i];
					}
				}
				else if(month%2==0 && month!=2)
				{
					for(i = 1;i<=30;i++)
					{
							obj[month][i].Display();
							t[i] = obj[month][i];
					}
				}
				else if(month == 2)
				{
					for(i = 1;i<=28;i++)
					{
							obj[month][i].Display();
							t[i] = obj[month][i];
					}
				}

				avg.Average(t);

			}
			else
			{
				cout<<"\nEnter a proper month.";
			}

			break;

		case 3 :
			return 0;

		default :
			cout<<"\nSelect a appropriate option.";
		}
	}

	return 0;
}

void weather ::Input(int day)
{
	day_of_month = day;

	cout<<"Enter High Temperature : ";
	cin>>high_temp;

	cout<<"Enter Low Temperature : ";
	cin>>low_temp;

	cout<<"Enter amount of rain : ";
	cin>>amount_rain;

	cout<<"Enter amount of snow : ";
	cin>>amount_snow;

}

void weather ::Display()
{
	cout<<"\n"<<day_of_month<<" \t "<<high_temp<<" \t "<<low_temp<<" \t "<<amount_rain<<" \t "<<amount_snow;
}

void weather ::Average(weather *t)
{
	float ht=0, lt=0, ar=0, as=0;
	int c = 0;

	for(int i=1;i<31;i++)
	{
		if(t[i].day_of_month!=99)
		{
			ht = ht + t[i].high_temp;
			lt = lt + t[i].low_temp;
			ar = ar + t[i].amount_rain;
			as = as + t[i].amount_snow;

			c++;
		}
	}

	ht = ht/c;
	lt = lt/c;
	ar = ar/c;
	as = as/c;

	cout<<"\n...................................";
	cout<<"\n"<<"Avg"<<"\t "<<ht<<" \t "<<lt<<" \t "<<ar<<" \t "<<as;
}
