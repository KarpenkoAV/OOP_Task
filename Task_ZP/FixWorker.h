#pragma once
#include "worker.h"
class FixWorker :
	public Worker
{
protected:
	double fix_zp;
public:
	FixWorker(void);
	FixWorker(const FixWorker&); //конструктор копирования
	FixWorker(int,string, double); //конструктор с параметрами
	virtual ~FixWorker(void);
	void CalcZp(void){zp=fix_zp;} //Расчет ЗП
	friend ostream& operator<<(ostream&,const FixWorker&); //перегрузка << для вывода в консоль
	friend ofstream& operator<<(ofstream&, FixWorker* );//перегрузка << для вывода в файл
	friend istream& operator>>(istream&,FixWorker&);//перегрузка оператора >> для ввода из консоли
	friend ifstream& operator>>(ifstream&, FixWorker*); //перегрузка >> для ввода из файла
};

