// lab10.cpp: определяет точку входа для консольного приложения.
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
	cout << "Введите количество эл-ов которые вы хотите ввести в S и S1: "; cin >> n;
	cout << "Заполнение дерева S: " << endl;
	for (int i = n; i > 0; i--)
	{
		cin >> k;
		S.TF_vvod(S.gettree(), k);
	}
	cout << "Заполнение дерева S1: " << endl;
	for (int i = n; i > 0; i--)
	{
		cin >> k;
		S1.TF_vvod(S1.gettree(), k);
	}
	cout << "Дерево S: " << endl;
	S.Tree_print(S.gettree(),0);
	cout << endl;
	cout << "Дерево S1: " << endl;
	S1.Tree_print(S1.gettree(),0);
	cout << endl; n = 0;
	cout << "Сумма значений, находящихся в листьях деревьев S и S1: "; S.TF_vsum(n);
	cout << "Удаление максимального элемента дерева S: " << endl;
	S.TF_Del();
	cout << "Дерево S: " << endl;
	S.Tree_print(S.gettree(),0);
	cout << endl;
	cout << "Удаление максимального элемента дерева S1: " << endl;
	S1.TF_Del();
	cout << "Дерево S1: " << endl;
	S1.Tree_print(S1.gettree(),0);
	cout << endl;
	system("pause");
	return 0;
}

