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
	void AddWorker(void);   //������� ���������� ������ ��������� � ������
	void Show(void);        //������� ������ ������ �� �����
	void SortMinZp(void);   //������� ���������� ������ �� �������� �������������� ��, ���� �� ���������� �� �� �������� �� �����
	void ReadFile(string&); //������� ������ ������ �� ����� � ������ �����������
	void WriteFile(string&);//������� ������ ������ �� ������ ����������� � ����
	void First5name(void);  //������� ������ ������ ���� ���� ���������� �� ������
	void End3ident(void);   //������� ������ ��������� ���� ��������������� ���������� �� ������
};

