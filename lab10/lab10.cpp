// lab10.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "iostream"
#include "Tree.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "RUS");
	int n,k;
	TreeFunction S;
	TreeFunction S1(6);
	cout << "������� ���������� ��-�� ������� �� ������ ������ � S � S1: "; cin >> n;
	cout << "���������� ������ S: " << endl;
	for (int i = n; i > 0; i--)
	{
		cin >> k;
		S.TF_vvod(S.gettree(), k);
	}
	cout << "���������� ������ S1: " << endl;
	for (int i = n; i > 0; i--)
	{
		cin >> k;
		S1.TF_vvod(S1.gettree(), k);
	}
	cout << "������ S: " << endl;
	S.Tree_print(S.gettree(),0);
	cout << endl;
	cout << "������ S1: " << endl;
	S1.Tree_print(S1.gettree(),0);
	cout << endl; n = 0;
	cout << "����� ��������, ����������� � ������� �������� S � S1: "; S.TF_vsum(n);
	cout << "�������� ������������� �������� ������ S: " << endl;
	S.TF_Del();
	cout << "������ S: " << endl;
	S.Tree_print(S.gettree(),0);
	cout << endl;
	cout << "�������� ������������� �������� ������ S1: " << endl;
	S1.TF_Del();
	cout << "������ S1: " << endl;
	S1.Tree_print(S1.gettree(),0);
	cout << endl;
	system("pause");
	return 0;
}

