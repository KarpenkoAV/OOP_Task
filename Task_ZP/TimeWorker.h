#pragma once
#include "worker.h"
class TimeWorker :
	public Worker
{
protected:
	double hour_rate;
public:
	TimeWorker(void);
	TimeWorker(int,string, double); //конструктор с параметрами
	TimeWorker(const TimeWorker&); //конструктор копирования
	virtual ~TimeWorker(void);
	void CalcZp(void){zp=20.8*8*hour_rate;} //расчет ЗП
	friend ostream& operator<<(ostream&,const TimeWorker&); //перегрузка << для вывода в консоль
	friend ofstream& operator<<(ofstream&, TimeWorker* ); //перегрузка << для вывода в файл
	friend istream& operator>>(istream&,TimeWorker&);//перегрузка оператора >> для ввода из консоли
	friend ifstream& operator>>(ifstream&, TimeWorker* ); //перегрузка >> для ввода из файла
};

