#pragma once
#include "rect.h"
class Cuboid :
	public Rect
{
protected:
	int h;
public:
	int geth(){return h;}
	void changeh(int new_h){h=new_h;}
Cuboid(const int& x, const int& y, const int& d, const int& w, const int& h):
	Rect(x,y,d,w),h(h){}
int getVol() const
{
	return getArea()*h;
}
int getCuArea() const
{
	return 2*(d*w+d*h+w*h);
}
};

