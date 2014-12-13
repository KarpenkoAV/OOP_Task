#pragma once
class Firma
{
protected:
vector <Worker*> sp;
vector <Worker*>::iterator iter;
Worker* ptr;
public:
	Firma(void);
	virtual ~Firma(void);
	void AddWorker(void);   //Функция добавления нового работника в список
	void Show(void);        //Функция вывода списка на экран
	void SortMinZp(void);   //Функция сортировки списка по убыванию среднемесячной ЗП, если ЗП одинаковая то по алфавиту по имени
	void ReadFile(string&); //Функция чтения данных из файла в список сотрудников
	void WriteFile(string&);//Функция записи данных из списка сотрудников в файл
	void First5name(void);  //Функция вывода первых пяти имен работников из списка
	void End3ident(void);   //Функция вывода последних трех идентификаторов работников из списка
};

