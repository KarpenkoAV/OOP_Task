#pragma once
#include "worker.h"
class TimeWorker :
	public Worker
{
protected:
	double hour_rate;
public:
	TimeWorker(void);
	TimeWorker(int,string, double); //����������� � �����������
	TimeWorker(const TimeWorker&); //����������� �����������
	virtual ~TimeWorker(void);
	void CalcZp(void){zp=20.8*8*hour_rate;} //������ ��
	friend ostream& operator<<(ostream&,const TimeWorker&); //���������� << ��� ������ � �������
	friend ofstream& operator<<(ofstream&, TimeWorker* ); //���������� << ��� ������ � ����
	friend istream& operator>>(istream&,TimeWorker&);//���������� ��������� >> ��� ����� �� �������
	friend ifstream& operator>>(ifstream&, TimeWorker* ); //���������� >> ��� ����� �� �����
};

