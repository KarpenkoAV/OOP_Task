#pragma once
class Worker //����������� ������� �����
{
protected:
	string name;
	int ident;
	double zp;
public:
	Worker(void);
	virtual ~Worker(void);
	virtual void CalcZp()=0; //������ ����������� ������� ������� �� (������ ���� ����������� � ������ ������ ����������)
	virtual void Show(void); //������� ������� ���������� � ���������
	bool operator<(Worker&); //
	string Getname(void);
	int GetIndent(void);
};

