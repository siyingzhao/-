#include "Cuboid.h"

int main()
{
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	Point p1(x1,y1),p2(x2,y2);
	Rect rect(p1,p2);
	int h;
	cin>>h;
	Cuboid cuboid(x1,y1,rect.getd(),rect.getw(),h);
	int new_x,new_h;
	cin>>new_x>>new_h;
	cuboid.changex(new_x);
	cuboid.changeh(new_h);
	cout<<fixed<<setprecision(2)<<p1.dist(p2)<<endl;
	cout<<rect.getArea()<<endl;
	cout<<cuboid.getVol()<<endl;
	cout<<cuboid.getCuArea()<<endl;
	system("pause");
	return 0;
}
