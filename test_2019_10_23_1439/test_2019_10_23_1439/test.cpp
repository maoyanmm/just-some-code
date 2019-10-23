#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<assert.h>
#include<string.h>
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_pData = (int*)malloc(capacity * sizeof(int));
		assert(_pData);
		_size = 0;
		_capacity = capacity;
	}

	~SeqList()
	{
		if (_pData)
		{
			free(_pData);
			_pData = nullptr;
			_size = 0;
			_capacity = 0;
			cout << "~SeqList(_)" << endl;
		}
	}
private:
	int* _pData;
	int _size;
	int _capacity;
};

class String
{
public:
	String(const char* str = "hello")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		cout << "~String(_)" << endl;
		free(_str);
	}

private:
	char* _str;
};

class Person
{
public:
	~Person()
	{
	}
private:
	String _name;
	int _age;
};

class Time
{
public:
	Time()
	{
		cout << "Time(_)" << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date()
	{
		_year = 2019;
		_month = 10;
		_day = 23;
	}

	Date(int year , int month = 9, int day = 3)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void SetDate(int year , int month = 4, int day = 18)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool operator==(const Date& d2)
	{
		return _year == d2._year 
			&& _month == d2._month 
			&& _day == d2._day;
	}

	/*Date& operator=(const Date& d3)
	{
		if (this != &d3)
		{
			this->_year = d3._year;
			this->_month = d3._month;
			this->_day = d3._day;
		}
	}*/

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};





void test()
{
	/*Date d1;
	d1.Display();*/
	/*Date d2(1997,04,18);
	d2.Display();*/
	/*SeqList s;*/
	/*char* a = "\0";
	int len = strlen(a);
	int size = sizeof(a);
	cout << "len" << "-" << len << "-" << "size" <<"-"<< size << endl;
	char* b = "ss";
	len = strlen(b);
	size = sizeof(b);
	cout << "len" << "-" << len << "-" << "size" <<"-"<< size << endl;
	char c[2] = "\0";*/
	/*Person p;*/
	/*Date d1(1997, 4, 18);
	d1.Display();
	Date d2(d1);
	d2.Display();
	Date d3;
	d3.Display();
	Date d4(Date(2008, 8, 8));
	d4.Display();*/
	/*String s1("mayao");
	String s2(s1);*/
	Date d1;
	Date d2(1997,4,18);
	cout << (d1 == d2) << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}