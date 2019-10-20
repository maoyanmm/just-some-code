#include<iostream>
using namespace std;

namespace N1
{
	int a = 1;
	inline int Add(int a, int b)
	{
		return a + b;
	}
}

void fun1(int a , int b = 1, int c = 3)
{
	cout << a << b << c << endl;
}

struct A
{
	int a; // 4 1 1        0 ~ 3          4 8 4  0~3
	char b; // 1 1 1       4 ~ 4          1 8 1  4~4
	double c;// 8 1 1      5 ~ 12         8 8 8  8~15 
};

union F
{
	int a;
	char b;
};

void test()
{
	int b = 1;// 0000 0000 0000 0001
	int* p = &b;
	char* pp = (char*)p;//0001
	if (*pp == 0)
	{
		cout << "big" << endl;
	}
	else
	{
		cout << "little" << endl;
	}
	F f;
	f.a = 1;
	f.b = f.a;
	cout << f.b << endl;
	int* p = NULL;
	int* p = 0;
	int* p = nullptr;
	int a = 1;
	int b = 2;
	char x = 'x';
	int& qqa = a;
	qqa = b;
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	auto d = 1;
	cout << typeid(d).name() << endl;
	auto& e = a;
	cout << typeid(e).name() << endl;
	auto y = &x;
	cout << typeid(y).name() << endl;
	auto z = &a;
	cout << typeid(z).name() << endl;
	for (auto& e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto e : arr)
	{
		e *= 2;
	}
	for (auto& e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	int c = N1::Add(N1::a, 3);
	cout << c << " ";
}



int main()
{
	test();
	system("pause");
	return 0;
}