#pragma once
class Worker //Абстрактный базовый класс
{
protected:
	string name;
	int ident;
	double zp;
public:
	Worker(void);
	virtual ~Worker(void);
	virtual void CalcZp()=0; //чистая виртуальная функция расчета ЗП (должна быть реализована в каждом классе наследнике)
	virtual void Show(void); //функция выводит информацию о работнике
	bool operator<(Worker&); //
	string Getname(void);
	int GetIndent(void);
};

