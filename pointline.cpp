/*
点与直线
用于说明类的组合，
郑莉，C++程序设计，清华大学出版社，例4-4，P118-P120
sunlupeng,2021.2.23
*/
#include<iostream>
#include<cmath>
using namespace std;
class Point{
public:
	Point(int xx=0,int yy=0){
		x=xx;
		y=yy;
	}
	Point(Point &p);
	int getX(){return x;}
	int getY(){return y;}
private:
	int x,y;
};
Point::Point(Point &p){
	x=p.x;
	y=p.y;
	cout<<"Call the copy constructor of Point"<<endl;
}

//类的组合
class Line{
public:
	Line(Point xp1,Point xp2);
	Line(Line &l);
	double getLen(){return len;}
private:
	Point p1,p2;//Point类的对象p1,p2
	double len;
};

//组合类的构造函数
Line::Line(Point xp1,Point xp2):p1(xp1),p2(xp2){
	cout<<"Calling constructor of Line"<<endl;
	double x=static_cast<double>(p1.getX()-p2.getX());
	double y=static_cast<double>(p1.getY()-p2.getY());
	len=sqrt(x*x+y*y);
}

//组合类的复制构造函数
Line::Line(Line &l):p1(l.p1),p2(l.p2){
	cout<<"Calling the copy constructor of Line"<<endl;
	len=l.len;
}

//主函数
int main(){
	Point myp1(1,1), myp2(4,5);
	Line line(myp1,myp2);	//调用了4次Point类的复制构造函数，传参两次，初始化内嵌对象两次
	Line line2(line);		//调用了3次复制构造函数，Line类的1次，Point类两次
	cout<<"The length of the line is:";
	cout<<line.getLen()<<endl;
	cout<<"The length of the line2 is:";
	cout<<line2.getLen()<<endl;
	/**/
	return 0;
}
/*
运行结果：
Call the copy constructor of Point
Call the copy constructor of Point
Call the copy constructor of Point
Call the copy constructor of Point
Calling constructor of Line
Call the copy constructor of Point
Call the copy constructor of Point
Calling the copy constructor of Line
The length of the line is:5
The length of the line2 is:5
Press any key to continue
*/