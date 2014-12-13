#include "StdAfx.h"
#include "Firma.h"


Firma::Firma(void)
{
}


Firma::~Firma(void)
{
}

void Firma::AddWorker() //������� ���������� ������ ��������� � ������
{
	char key;

L1:	cout<<"Input type worker: 1- Fix stavka, 2- Time stavka, Any - Exit\n";
	cout<<"->";
	cin>>key;
	switch (key)
     {
            case '1': //�������� � ������������� �������
				cout<<"---------Worker Fix stavka ----------------------\n" ;
				ptr= new FixWorker(); //������� ����� ������ FixWorker � ����� ����������� ��������� ptr
				cin>>*(dynamic_cast<FixWorker*>(ptr)); //��������� �������� >> ���������� ��� FixWorker ��������� �������� ���������� ����� dynamic_cast
				sp.push_back(ptr);//��������� � ������ ��������� �� FixWorker
				goto L1;
            break;
			case '2': //�������� � ��������� �������
				cout<<"---------Worker Time stavka ----------------------\n" ;
				ptr= new TimeWorker(); //������� ����� ������ TimeWorker � ����� ����������� ��������� ptr
			    cin>>*(dynamic_cast<TimeWorker*>(ptr));	//��������� �������� >> ���������� ��� TimeWorker ��������� �������� ���������� ����� dynamic_cast	
				sp.push_back(ptr);//��������� � ������ ��������� �� TimeWorker
				goto L1;
            break;
			default:
			break;
	 }

}

void Firma::Show(void) //������� �������� ��� �������� �������
{
	iter=sp.begin(); //������������� �������� �� ������ ������� sp
	while(iter!=sp.end()) //���� �� ����� sp
	{
		(*iter)->Show(); //����� ������������� �������� *iter ���������� �� �������� ������, � ��������� ��� ���������,  �� ����� ���� � ������� Show 
		                 //������������� � ������ ������ TimeWorker � FixWorker � ����������� � Woker ��� ������ ����������� 
		cout<<"\n";      
		iter++;         //����������� ��������
	}
}

void Firma::SortMinZp(void) //������� ���������� ������� sp �� �������� ��������������� ���������
{
	for(int i=0;i<sp.size();i++)//��������� ������ sp
	{
		for(int j=i+1;j<sp.size();j++) //���� ��� ��������� �������� �������� �� ����� ������������
			if(*(sp[i])<*(sp[j])) //���� ������� ������� ������ ������ ������ �� ����������� ���������.
				                  //���������� ��������� �� ������� ����� Worker, �������� < ���������� � ������� ������ Worker �� ������ ���������� ���������
				swap(sp[j],sp[i]); //����� ������ �� ������� (���������, �� �������� � �����������)   
	}

}

void Firma::ReadFile(string& nfile) //������� ������ ������� � ������ (��������� ������� �����������)
{
	sp.clear(); //������� ������
	string strf;
	ifstream fin(nfile,ios::in); ///������������� ���� nfile � ����� ������
	if(!fin) //������� ������� ���� ��� ������
	{
		cout<<"cannot open file for read";
	}
	while(!fin.eof()) //���� �� ����� �����
	{
		strf="";
		fin>>strf; //������ � ���������� ������ (��� ������ � ����� ��������� ���������)

		if(strf=="TimeWorker") //���� ��������� TimeWorker, ������ �� ��� ���� ������ ����� ������
		{
			TimeWorker tw; //������� ������ ���� TimeWorker
			fin>>&tw; //��������� �������� >> ifstream ���������� � ������ TimeWorker ��� ��������� ��������� �������� ������ ������ & ��� ������� tw
			ptr= new TimeWorker(tw);//ptr-��� ��������� �� ����������� ������� ����� Worker, ������� ����� ������ TimeWorker � �������� � ����
			                        //� ������� ������������ ����������� � TimeWorker ��� ���� ������� tw
			sp.push_back(ptr);      //��������� ��������� � ������ sp (���������� �������� ������ Worker)
		}
		if(strf=="FixWorker")
		{
			FixWorker fw;
			fin>>&fw; //��������� �������� >> ifstream ���������� � ������ FixWorker ��� ��������� ��������� �������� ������ ������ & ��� ������� fw
			ptr= new FixWorker(fw);//ptr-��� ��������� �� ����������� ������� ����� Woker, ������� ����� ������ FixWorker � �������� � ����
			                        //� ������� ������������ ����������� � FixWorker ��� ���� ������� fw
			sp.push_back(ptr);      //��������� ��������� � ������ sp (���������� �������� ������ Worker)
		}
       
	}
		fin.close(); //��������� ����
}

void Firma::WriteFile(string& nfile) //������� ������ �������� ����� ������� �� ������ � ����
{
	iter=sp.begin();//������������� �������� �� ������ �������

	ofstream fout(nfile,ios::out); //������������� ���� nfile � ����� ������
	if(!fout) //������� ������� ���� ��� ������
	{
		cout<<"cannot open file for write";
	}
	int i=0;
	while(iter!=sp.end()) //���� �� ����� �������
	{   
		if(TimeWorker* pt=dynamic_cast<TimeWorker*>(*iter))//�������� RTTI ���� ��������� �� ������� ���������� ��������� �� ����� TimeWorker
		{
		   fout<<typeid(*pt).name()<<" "; //�������� ��� ������ � ����
		   fout<<pt; //���������� �������� ����� ������ TimeWorker � ���� ����� ������������� � ������ TimeWorker << ��� ofstream (��� ���������)
		}
		if(FixWorker* pt=dynamic_cast<FixWorker*>(*iter))//�������� RTTI ���� ��������� �� ������� ���������� ��������� �� ����� FixWorker
		{
		   fout<<typeid(*pt).name()<<" "; //�������� ��� ������ � ����
		   fout<<pt; //���������� �������� ����� ������ TimeWorker � ���� ����� ������������� � ������ FixWorker << ��� ofstream (��� ���������)
		}
		iter++;
	}
		fout.close(); //��������� ���� 
		cout<<"Write file "<<nfile<<"\n";
}

void Firma::First5name(void) //������� ������ ������ ���� ��������� ������
{
	iter=sp.begin();//������������� �������� �� ������ �������
	int cnt=0; //�������� ������� ������� ��� ������
	while(iter!=sp.end() && cnt<5) //��������� � ����� ������� � ����������� 5 �������
	{
		cout<<cnt+1<<".name=> "<<(*iter)->Getname()<<"\n";//������� ������
		iter++;
		cnt++;
	}
}

void Firma::End3ident(void) //������� ������ ��������� ���� ��������� ������
{
	iter=sp.end()-1; //������������� �������� �� ��������� ������� (�������� 1 ��������� sp.end() ��������� �� ������� �������)
	int cnt=0; //�������� ������� ������� ��� ������
	while(iter!=sp.begin() && cnt<3) //��������� � ������ ������� � ����������� 3 ������ � �����
	{
		cout<<cnt+1<<". identifier=> "<<(*iter)->GetIndent()<<"\n"; //������� ������
		iter--;//��������� �� 1 � ������ �������
		cnt++; //����������� �� 1 ������� �������
	}
}