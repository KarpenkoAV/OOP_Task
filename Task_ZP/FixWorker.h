#pragma once
#include "worker.h"
class FixWorker :
	public Worker
{
protected:
	double fix_zp;
public:
	FixWorker(void);
	FixWorker(const FixWorker&); //����������� �����������
	FixWorker(int,string, double); //����������� � �����������
	virtual ~FixWorker(void);
	void CalcZp(void){zp=fix_zp;} //������ ��
	friend ostream& operator<<(ostream&,const FixWorker&); //���������� << ��� ������ � �������
	friend ofstream& operator<<(ofstream&, FixWorker* );//���������� << ��� ������ � ����
	friend istream& operator>>(istream&,FixWorker&);//���������� ��������� >> ��� ����� �� �������
	friend ifstream& operator>>(ifstream&, FixWorker*); //���������� >> ��� ����� �� �����
};

