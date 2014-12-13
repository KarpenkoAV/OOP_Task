#include "StdAfx.h"
#include "Firma.h"


Firma::Firma(void)
{
}


Firma::~Firma(void)
{
}

void Firma::AddWorker() //Функция добавления нового работника в вектор
{
	char key;

L1:	cout<<"Input type worker: 1- Fix stavka, 2- Time stavka, Any - Exit\n";
	cout<<"->";
	cin>>key;
	switch (key)
     {
            case '1': //Работник с фиксированной оплатой
				cout<<"---------Worker Fix stavka ----------------------\n" ;
				ptr= new FixWorker(); //создаем новый объект FixWorker и адрес присваиваем указателю ptr
				cin>>*(dynamic_cast<FixWorker*>(ptr)); //поскольку оператор >> перегружен для FixWorker выполняем операцию приведения типов dynamic_cast
				sp.push_back(ptr);//добавляем в вектор указатель на FixWorker
				goto L1;
            break;
			case '2': //Работник с почасовой оплатой
				cout<<"---------Worker Time stavka ----------------------\n" ;
				ptr= new TimeWorker(); //создаем новый объект TimeWorker и адрес присваиваем указателю ptr
			    cin>>*(dynamic_cast<TimeWorker*>(ptr));	//поскольку оператор >> перегружен для TimeWorker выполняем операцию приведения типов dynamic_cast	
				sp.push_back(ptr);//добавляем в вектор указатель на TimeWorker
				goto L1;
            break;
			default:
			break;
	 }

}

void Firma::Show(void) //Функция показать все элементы вектора
{
	iter=sp.begin(); //устанавливаем итератор на начало вектора sp
	while(iter!=sp.end()) //пока не конец sp
	{
		(*iter)->Show(); //через разименованый итератор *iter добираемся до элемента списка, а поскольку это указатель,  то через него к функции Show 
		                 //реализованной в каждом классе TimeWorker и FixWorker и объявленной в Woker как чистая виртуальная 
		cout<<"\n";      
		iter++;         //увеличиваем итератор
	}
}

void Firma::SortMinZp(void) //функция сортировки вектора sp по убыванию среднемесячного заработка
{
	for(int i=0;i<sp.size();i++)//сканируем вектор sp
	{
		for(int j=i+1;j<sp.size();j++) //цикл для сравнения текущего элемента со всеми последующими
			if(*(sp[i])<*(sp[j])) //если текущий элемент меньше какого нибудь из последующих элементов.
				                  //сравниваем указатели на базовый класс Worker, оператор < перегружен в базовом классе Worker со своими критериями сравнения
				swap(sp[j],sp[i]); //тогда меняем их местами (напоминаю, мы работаем с указателями)   
	}

}

void Firma::ReadFile(string& nfile) //Функция чтения обектов в список (структура классов сохраняется)
{
	sp.clear(); //очистка списка
	string strf;
	ifstream fin(nfile,ios::in); ///устанавливаем файл nfile в режим чтения
	if(!fin) //попытка открыть файл для чтения
	{
		cout<<"cannot open file for read";
	}
	while(!fin.eof()) //пока не конец файла
	{
		strf="";
		fin>>strf; //читаем в переменную данные (все данные в файле разделены пробелами)

		if(strf=="TimeWorker") //если встретили TimeWorker, значит за ним идут данные этого класса
		{
			TimeWorker tw; //создаем объект типа TimeWorker
			fin>>&tw; //поскольку оператор >> ifstream перегружен в классе TimeWorker для указателя выполняем операцию взятия адреса & для объекта tw
			ptr= new TimeWorker(tw);//ptr-это указатель на абстрактный базовый класс Worker, создаем новый объект TimeWorker и копируем в него
			                        //с помощью конструктора копирования в TimeWorker все поля объекта tw
			sp.push_back(ptr);      //добавляем указатель в вектор sp (указателей базового класса Worker)
		}
		if(strf=="FixWorker")
		{
			FixWorker fw;
			fin>>&fw; //поскольку оператор >> ifstream перегружен в классе FixWorker для указателя выполняем операцию взятия адреса & для объекта fw
			ptr= new FixWorker(fw);//ptr-это указатель на абстрактный базовый класс Woker, создаем новый объект FixWorker и копируем в него
			                        //с помощью конструктора копирования в FixWorker все поля объекта fw
			sp.push_back(ptr);      //добавляем указатель в вектор sp (указателей базового класса Worker)
		}
       
	}
		fin.close(); //закрываем файл
}

void Firma::WriteFile(string& nfile) //Функция записи объектов наших классов из списка в файл
{
	iter=sp.begin();//позиционируем итератор на начало вектора

	ofstream fout(nfile,ios::out); //устанавливаем файл nfile в режим записи
	if(!fout) //попытка открыть файл для записи
	{
		cout<<"cannot open file for write";
	}
	int i=0;
	while(iter!=sp.end()) //пока не конец вектора
	{   
		if(TimeWorker* pt=dynamic_cast<TimeWorker*>(*iter))//проверка RTTI если указатель из вектора указателей указывает на класс TimeWorker
		{
		   fout<<typeid(*pt).name()<<" "; //записать имя класса в файл
		   fout<<pt; //записываем значения полей класса TimeWorker в файл через перегруженный в классе TimeWorker << для ofstream (для указателя)
		}
		if(FixWorker* pt=dynamic_cast<FixWorker*>(*iter))//проверка RTTI если указатель из вектора указателей указывает на класс FixWorker
		{
		   fout<<typeid(*pt).name()<<" "; //записать имя класса в файл
		   fout<<pt; //записываем значения полей класса TimeWorker в файл через перегруженный в классе FixWorker << для ofstream (для указателя)
		}
		iter++;
	}
		fout.close(); //закрываем файл 
		cout<<"Write file "<<nfile<<"\n";
}

void Firma::First5name(void) //Функция вывода первых пяти элементов списка
{
	iter=sp.begin();//позиционируем итератор на начало вектора
	int cnt=0; //Обнуляем счетчик записей для вывода
	while(iter!=sp.end() && cnt<5) //двигаемся к концу вектора и отсчитываем 5 записей
	{
		cout<<cnt+1<<".name=> "<<(*iter)->Getname()<<"\n";//выводим записи
		iter++;
		cnt++;
	}
}

void Firma::End3ident(void) //Функция вывода последних трех элементов списка
{
	iter=sp.end()-1; //устанавливаем итератор на последний элемент (отнимаем 1 поскольку sp.end() указывает за границу вектора)
	int cnt=0; //Обнуляем счетчик записей для вывода
	while(iter!=sp.begin() && cnt<3) //двигаемся к началу вектора и отсчитываем 3 записи с конца
	{
		cout<<cnt+1<<". identifier=> "<<(*iter)->GetIndent()<<"\n"; //выводим записи
		iter--;//смещаемся на 1 к началу вектора
		cnt++; //увеличиваем на 1 счетчик записей
	}
}