//4_2.cpp
#include<iostream>
using namespace std;

class Point{
public:
	int dd=0;
	Point(int xx=0, int yy=0){//构造函数
		x=xx;
		y=yy;
		dd=1;
	}
	Point(Point &p);//复制构造函数
	int getX(){
		return x;
	}
	int getY(){
		return y;
	}
private:
	int x,y;//私有数据
};
//成员函数的实现
Point::Point(Point &p){
	x=p.x;
	y=p.y;
	cout<<"Calling the copy constructor"<<endl;
}
//形参为Point类对象的函数
void fun1(Point p){
	p.dd=2;
    cout<<p.getX()<<endl;
}

//返回值为Point类对象的函数
Point fun2(){
	Point a(1,2);
	return a;
}

//主程序
int main()
{
	Point a(4,5);
	cout<<"a--dd="<<a.dd<<endl;
	Point b=a;
	cout<<b.getX()<<endl;
	cout<<"b--dd="<<b.dd<<endl;
	fun1(b);
	cout<<"b--dd="<<b.dd<<endl;
	b=fun2();
	cout<<b.getX()<<endl;
	cout<<"a--dd="<<a.dd<<endl;
	return 0;
}


