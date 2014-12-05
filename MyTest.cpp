#include "stdafx.h"
#include<iostream> 
using namespace std; 

class TDate { 
	int year,month,day; 
public: 
	TDate(int y=2007,int m=1,int d=1);
	TDate(const TDate &date); 
	~TDate(); 
	void Print(); 
}; 

TDate::TDate(int y,int m,int d) { 
	year = y; 
	month = m; 
	day = d; 
	cout<<"Constructor called.\n"; 
} 

TDate::TDate(const TDate &date) { 
	year = date.year; 
	month = date.month; 
	day = date.day; 
	cout<<"Copy Constructor called.\n"; 
} 

void TDate::Print() {
	cout<<year<<"_"<<month<<"_"<<day<<endl; 
} 

TDate::~TDate() { 
	cout<<"Destructor called.\n"; 
} 

TDate f(TDate Q) { 
	TDate R(Q); 
	return Q; 
} 

void run_mytest() { 
	TDate day1(1998,5,26); 
	TDate day3; 
	TDate day2(day1); 
	TDate day4 = day2; 
	day3 = day2; 
	day3 = f(day2); 
	day3.Print(); 
} 