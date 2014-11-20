#include<iostream>
using namespace std;
class date
{
public:
	int year,month,day;
	int passdaycal();
	int daynumcal();
};
int date::daynumcal()
{
	int runnian=1;
	int daynum=0;
	if(this->year%4!=0||(this->year%100==0&&this->year%400!=0))
		runnian=0;
	switch (runnian)
	{
	case 0:
		switch(this->month)
		{
		case 1:daynum=this->day;break;
		case 2:daynum=31+this->day;break;
		case 3:daynum=59+this->day;break;
		case 4:daynum=90+this->day;break;
		case 5:daynum=120+this->day;break;
		case 6:daynum=151+this->day;break;
		case 7:daynum=181+this->day;break;
		case 8:daynum=212+this->day;break;
		case 9:daynum=242+this->day;break;
		case 10:daynum=273+this->day;break;
		case 11:daynum=303+this->day;break;
		case 12:daynum=334+this->day;break;
		}break;
	case 1:
		switch(this->month)
		{
		case 1:daynum=this->day;break;
		case 2:daynum=31+this->day;break;
		case 3:daynum=59+this->day+1;break;
		case 4:daynum=90+this->day+1;break;
		case 5:daynum=120+this->day+1;break;
		case 6:daynum=151+this->day+1;break;
		case 7:daynum=181+this->day+1;break;
		case 8:daynum=212+this->day+1;break;
		case 9:daynum=242+this->day+1;break;
		case 10:daynum=273+this->day+1;break;
		case 11:daynum=303+this->day+1;break;
		case 12:daynum=334+this->day+1;break;
		}
		break;
	}
	return daynum;
}
int date::passdaycal()
{
	int i=0;
	int passdaynum;
	if(this->year>2000&&this->year<2100)
	i=(this->year-2001)/4+1;
	else if(this->year==2000)
		i=0;
	else if(this->year>=2100)
		i=(this->year-2001)/4+1-(this->year-2000)/100+(this->year-2000)/400;
	passdaynum=(this->year-2000)*365-1+i+this->daynumcal();
	return passdaynum;
}
int main()
{
	date a[100];
	int icon=0;
	for(int i=0;;i++)
	{
	cin>>a[i].year;
	if(a[i].year==-1)
		break;
	cin>>a[i].month>>a[i].day;
	icon++;	
	}
	for(int j=0;j<icon;j++)
	{
		cout<<a[j].passdaycal()<<endl;
	    cout<<a[j].daynumcal()<<endl;
	}
	system("pause");
	return 0;
}