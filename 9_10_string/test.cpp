#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

//int main()
//{
//	string s = "abcdefgabcdefg";
//	int cout[26] = { 0 };
//	for (auto ch : s)
//	{
//		cout[ch - 'a']++;
//	}
//
//	return 0;
//}



class time;

class Hy
{
public:
	
	void print(const Time& t);
	

};


class Time
{
public:
	Time(int year = 0, int month = 0, int day = 0)
		:_year(year)
		,_month(month)
		,_day(day)
	{ }

	friend void Hy::print(const Time& t);

private:
	int _year;
	int _month;
	int _day;
};

void Hy::print(const Time& t)
{
	cout << t._year << " " << t._month << " " << t._day << endl;
}