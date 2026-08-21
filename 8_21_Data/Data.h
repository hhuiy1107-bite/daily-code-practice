#pragma once


#include <iostream>
using namespace std;

class Data
{

public:
	//¹¹Ôìº¯Êı
	Data(int year, int month, int day);

	Data& operator+=(int num);

	int GetMonthDay(int year, int month);

	void print();


private:
	int _year;
	int _month;
	int _day;
};