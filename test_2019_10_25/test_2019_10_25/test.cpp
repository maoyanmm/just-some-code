#include<iostream>
using namespace std;

class Date
{
public:
	/*Date(int year = 2008, int month = 8, int day = 8)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/

	int getDay(int year, int month)
	{
		int arr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int days = arr[month - 1];
		if (month == 2)
		{
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)
			{
				days++;
			}
		}
		return days;
	}

	Date(int year , int month , int day )
	{
		//判断日期输入的是否正确
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{

	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	Date operator+(int days)
	{
		int day = this->_day + days;
			while (day > 28)
			{
				if (this->_month == 12 && day > 31)
				{
					this->_month = 1;
					this->_year++;
					day -= 31;
				}
				else if ((this->_month == 1 || this->_month == 3 || this->_month == 5 || this->_month == 7
					|| this->_month == 8 || this->_month == 10) && (day > 31))
				{
					this->_month++;
					day -= 31;
				}
				else if (this->_month == 2 && (day >28))
				{
					this->_month++;
					day -= 28;
				}
				else if ((this->_month == 4 || this->_month == 6 || this->_month == 9 
					|| this->_month == 11) && (day > 30))
				{
					this->_month++;
					day -= 30;
				}
				else
				{
					break;
				}
			}
			this->_day = day;
			return *this;
	}

	Date operator-(int days)
	{
		Date tmp = *this;
		tmp._day = tmp._day - days;
		while (tmp._day <= 0)
		{
			tmp._month--;
			if (tmp._month == 0)
			{
				tmp._month = 12;
				tmp._year--;
			}
			tmp._day += getDay(tmp._year, tmp._month);
		}
		return tmp;
		/*int day = this->_day - days;
		while (day <= 0)
		{
			if (this->_month == 1 && day <= 0)
			{
				this->_year--;
				this->_month = 12;
				day += 31;
			}
			else if ((this->_month == 2 || this->_month == 4 || this->_month == 6 || this->_month == 8
				|| this->_month == 9 || this->_month == 11 ) && (day <= 0))
			{
				this->_month--;
				day += 31;
			}
			else if (this->_month == 3 && (day <= 0))
			{
				this->_month--;
				day += 28;
			}
			else if ((this->_month == 5 || this->_month == 7 || this->_month == 10 
				|| this->_month == 12) && (day <= 0))
			{
				this->_month--;
				day += 30;
			}
			else
			{
				break;
			}
		}
		this->_day = day;
		return *this;*/
	}

	int operator-(const Date& d)//2019_10_25
	{                         //2019_9_27
		Date d2 = d;
		int day1 = 0;
		int day2 = 0;
		int year = _year - d2._year;
		/*if (_day == d._day)*/
		while (_month > 1)
		{
			if (this->_month == 12 || this->_month == 3 || this->_month == 5 || this->_month == 7
				|| this->_month == 8 || this->_month == 10)
			{
				day1 += 31;
				_month--;
			}
			else if (this->_month == 2)
			{
				day1 += 28;
				_month--;
			}
			else if (this->_month == 4 || this->_month == 6 || this->_month == 9
				|| this->_month == 11)
			{
				day1 += 30;
				_month--;
			}
		}

		while (d2._month > 1)
		{
			if (d2._month == 12 || d2._month == 3 || d2._month == 5 || d2._month == 7
				|| d2._month == 8 || d2._month == 10)
			{
				day2 += 31;
				d2._month--;
			}
			else if (d2._month == 2)
			{
				day2 += 28;
				d2._month--;
			}
			else if (d2._month == 4 || d2._month == 6 || d2._month == 9
				|| d2._month == 11)
			{
				day2 += 30;
				d2._month--;
			}
		}
		day1 = day1 + _day;
		day2 = day2 + d2._day;
		int day = day1 - day2 + year * 365;
		return day;
	}

	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void test()
{
	Date d(2008,8,8);
	d = d - 30;
	d.Display();
	/*Date d1;
	d1.Display();
	Date d2;
	d2 = d2 + 256;
	d2.Display();
	int ret = d2 - d1;
	cout << "ret=" << ret << endl;*/
	/*d1 = d1 - 734;
	d1.Display();*/
	/*d2.Display();*/
}

int main()
{
	test();
	system("pause");
	return 0;
}