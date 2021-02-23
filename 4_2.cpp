//4_2.cpp
#include<iostream>
using namespace std;

class Point{
public:
	int dd=0;
	Point(int xx=0, int yy=0){//���캯��
		x=xx;
		y=yy;
		dd=1;
	}
	Point(Point &p);//���ƹ��캯��
	int getX(){
		return x;
	}
	int getY(){
		return y;
	}
private:
	int x,y;//˽������
};
//��Ա������ʵ��
Point::Point(Point &p){
	x=p.x;
	y=p.y;
	cout<<"Calling the copy constructor"<<endl;
}
//�β�ΪPoint�����ĺ���
void fun1(Point p){
	p.dd=2;
    cout<<p.getX()<<endl;
}

//����ֵΪPoint�����ĺ���
Point fun2(){
	Point a(1,2);
	return a;
}

//������
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


