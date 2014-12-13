#include "StdAfx.h"
#include "TimeWorker.h"


TimeWorker::TimeWorker(void):Worker(),hour_rate(0){}

TimeWorker::TimeWorker(int id, string nam, double pay) //����������� � �����������
{
  ident = id;
  name=nam;
  hour_rate=pay;
  CalcZp();
}

TimeWorker::TimeWorker(const TimeWorker& TW) //����������� �����������
{
	this->hour_rate =TW.hour_rate;
	this->ident=TW.ident;
	this->name = TW.name;
	this->CalcZp();
}

TimeWorker::~TimeWorker(void)
{
}


ostream& operator<<(ostream& obj,const TimeWorker& TW) //���������� << ��� ������ � �������
{
	 	  cout<<TW.ident<<"  "<<TW.name<<"  "<<TW.hour_rate<<"  "<<TW.zp;
return obj;
}

ofstream& operator<<(ofstream& obj, TimeWorker* TW ) //���������� << ��� ������ ������ � ����
{
	 	obj<<TW->ident<<" "<<TW->name<<" "<<TW->hour_rate<<"\n";
return obj;
}

istream& operator>>(istream& obj,TimeWorker& TW) //���������� ��������� >> ��� ����� �� �������
{
	cout<<"Name worker=>";
	cin>>TW.name;
	cout<<"Idetifier worker=>";
	cin>>TW.ident;
    cout<<"hour rate=>";
	cin>>TW.hour_rate;
	TW.CalcZp();
	return obj;
}

ifstream& operator>>(ifstream& obj, TimeWorker* TW ) //���������� >> ��� ����� ������ �� �����
{
	 	obj>>TW->ident>>TW->name>>TW->hour_rate;
		TW->CalcZp();
return obj;
}


