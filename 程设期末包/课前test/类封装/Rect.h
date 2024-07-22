#pragma once
#include "point.h"
class Rect :
	public Point
{
protected:
	int d;
	int w;
public:
	int getd(){return d;}
	int getw(){return w;}
	void changed(const int& a){d=a;}
	void changew(const int& b){w=b;}
	Rect(const int& x, const int& y, const int& d, const int& w):
		Point(x,y),d(d),w(w){}
	Rect(Point& p1, Point& p2):
		Point(p1.getx(),p1.gety()),
		d(p2.getx()-p1.getx()),
		w(p2.gety()-p1.gety()){}
	int getArea() const{return d*w;}
};

