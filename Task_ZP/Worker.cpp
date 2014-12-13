#include "StdAfx.h"
#include "Worker.h"


Worker::Worker(void):name(""),ident(0),zp(0) {}


Worker::~Worker(void)
{
}


bool Worker::operator<(Worker& W) //Перегружаем оператор < (с определенными условиями)
{
	if(this->zp<W.zp) //Если zp левого объекта меньше zp правого
		return true;  //возвращаем истину
	else //если больше либо рано
	{
		if(this->zp==W.zp) //Проверка на равенство zp 
			if(this->name[0] > W.name[0]) //Если zp равны, то проверяем имена сравниваем строки типа string
			  return true; 
			else return false;
		else return false;
	}	
	return false;
}
void Worker::Show(void) //Функция вывода информации об объекте
{
	cout<<ident<<" "<<name<<" "<<zp;
}
string Worker::Getname(void) //Функция получения имени работника, нужна для пункта б) условия задачи
{
	string n;
	return n=name;
}

int Worker::GetIndent(void) //Функция получения идентификатора работника, нужна для пункта с) условия задачи
{
	int i;
	return i=ident;
}