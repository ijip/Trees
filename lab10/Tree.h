#pragma once
#include "iostream"
using namespace std;
class Tree
{
protected:
	struct Derevo
	{
		int key;
		Derevo *parent, *left, *right;
	};
	Derevo *tree;
public:
	Tree() { tree = new Derevo; tree->key = 0; tree->left = 0; tree->parent = 0; tree->right = 0; } //конструктор по умолчанию
	void Tree_print (Derevo *T, int i) //вывод дерева прямым обходом
	{
		if (T)
		{
			Tree_print(T->right, i+1);
			for (int j = 1; j <= i * 5; j++) cout << " ";
			cout << T->key << " " << endl;
			Tree_print(T->left, i+1);
		}
	}
};

class TreeFunction : public Tree
{
public:
	TreeFunction() : Tree() {} //копирующий конструктор
	TreeFunction(int n) { tree = new Derevo; tree->key = n; tree->left = 0; tree->parent = 0; tree->right = 0; } //конструктор с параметрами
	~TreeFunction() {} //деструктор
	void TF_sum(Derevo *T, int &n)//подсчёт суммы значений, находящихся в листьях дерева
	{
		if (T)
		{
			if (T->left)
			{
				TF_sum(T->left, n);
			}
			if (T->right)
			{
				TF_sum(T->right, n);
			}
			if (!T->left && !T->right)
			{
				n = n + T->key;
			}
		}
	}
	void TF_vsum(int &n) //вывод результата функции TF_sum
	{
		TF_sum(tree, n);
		cout << n << endl;
	}
	void TF_Del() //удаление максимального элемента дерева
	{
		if (tree)
		{
			Derevo *q, *p = tree;
			if (p->right->right)
			{
				while (p->right->right)
				{
					p = p->right;
				}
				q = p->right;
				if (q->left)
				{
					p->right = q->left;
					delete q;
				}
				else
				{
					p->right = 0;
					delete q;
				}
			}
			else
			{
				if (p->right)
				{
					q = p->right;
					p->right = 0;
					delete q;
				}
				else
				{
					q = p;
					p = p->left;
					delete q;
				}
			}
		}
	}
	void TF_vvod(Derevo *&T, int n) //вставка нового элемента
	{
		if (T && T->key)
		{
			if (T->key > n)
			{
				TF_vvod(T->left, n);
			}
			if (T->key < n)
			{
				TF_vvod(T->right, n);
			}
		}
		else
		{
			if (T)
			{
				T->key = n;
			}
			else
			{
				T = new Derevo; T->parent = 0; T->left = 0; T->right = 0; T->key = n;
			}
		}
	}
	Derevo*& gettree()
	{
		return tree;
	}
};
