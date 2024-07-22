#pragma once
#include "iostream"
#include "iomanip"
#include "math.h"
#include "stdlib.h"
using namespace std;
class Point
{
protected:
	int x;
	int y;
public:
	int getx(){return x;}
	int gety(){return y;}
	void changex(const int& a){x=a;}
	void changey(const int& b){y=b;}
	Point(const int& x, const int& y):
		x(x),y(y){}
	float dist(const Point &p) const
	{
		float a,b;
		a=p.x-x;
		b=p.y-y;
		return sqrt(a*a+b*b);
	}
};

