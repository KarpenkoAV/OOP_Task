// Task_ZP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(void)
{   
	Firma firm; //создаем объект типа Firma
	string namef= "firma.sps"; //задаем имя файла для выгрузки/загрузки коллекции
	int key;
	char s;
L1:	cout<<"---------Input operation-----------\n";
	cout<<"1: Add worker in list \n";
	cout<<"2: Load workers with file \n";
	cout<<"3: Wrire workers in file \n";
	cout<<"4: Show worker \n";
	cout<<"5: Sort workers list \n";
    cout<<"6: Show 5 first names  workers \n";
	cout<<"7: Show 3 end identifier  workers \n";
	cout<<"0: Exit \n";
	cout<<"=>";
	cin>>key;
	switch(key)
	{
		case 1:
			firm.AddWorker();
			goto L1;
		break;
		case 2:
			firm.ReadFile(namef);
			firm.Show();

		break;
		case 3:
			firm.WriteFile(namef);
		break;
		case 4:
			firm.Show();
		break;
		case 5:
			firm.SortMinZp();
			firm.Show();
		break;
		case 6:
			firm.First5name();
		break;
		case 7:
			firm.End3ident();
		break;
	}
	cout<<" Select new operation? (y/n)=>";
	cin>>s;
	if(s=='y'|| s=='Y')
		goto L1;

	return 0;
}

