#include "StdAfx.h"
#include "Worker.h"


Worker::Worker(void):name(""),ident(0),zp(0) {}


Worker::~Worker(void)
{
}


bool Worker::operator<(Worker& W) //����������� �������� < (� ������������� ���������)
{
	if(this->zp<W.zp) //���� zp ������ ������� ������ zp �������
		return true;  //���������� ������
	else //���� ������ ���� ����
	{
		if(this->zp==W.zp) //�������� �� ��������� zp 
			if(this->name[0] > W.name[0]) //���� zp �����, �� ��������� ����� ���������� ������ ���� string
			  return true; 
			else return false;
		else return false;
	}	
	return false;
}
void Worker::Show(void) //������� ������ ���������� �� �������
{
	cout<<ident<<" "<<name<<" "<<zp;
}
string Worker::Getname(void) //������� ��������� ����� ���������, ����� ��� ������ �) ������� ������
{
	string n;
	return n=name;
}

int Worker::GetIndent(void) //������� ��������� �������������� ���������, ����� ��� ������ �) ������� ������
{
	int i;
	return i=ident;
}