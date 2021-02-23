/*
*例4-8，使用联合体保存成绩信息，并且输出
郑莉，C++语言程序设计，北京：清华大学出版社，P132
*/
#include<string>
#include<iostream>
using namespace std;

class ExamInfo{
public:
	//3种构造函数，分别用等级、是否通过和百分制来初始化
	ExamInfo(string name, char grade):name(name), mode(GRADE), grade(grade){}
	ExamInfo(string name, bool pass):name(name), mode(PASS), pass(pass){}
	ExamInfo(string name, int percent):name(name), mode(PERCENTAGE), percent(percent){}
	void show();
private:
	string name;	//课程名称
	enum{GRADE,PASS,PERCENTAGE} mode;//采用何种计分方式
	//无名成员？，无名联合体，可以直接访问这些成员中的一个，这三个成员共享内存空间
	union{
		char grade;	//等级制的成绩
		bool pass;	//是否通过
		int percent;	//百分制的成绩
	};
};
void ExamInfo::show(){
	cout<<name<<":";
	switch(mode)
	{
	case GRADE:
		cout<<grade;	//直接访问无名联合体的成员
		break;
	case PASS:	//直接访问无名联合体的成员
		cout<<(pass?"PASS":"FAIL");
		break;
	case PERCENTAGE:
		cout<<percent;	//直接访问无名联合体的成员
		break;
	}
	cout<<endl;
}

int main(){
	ExamInfo course1("English",'B');
	ExamInfo course2("Calculus",true);
	ExamInfo course3("C++ Programming", 85);
	course1.show();
	course2.show();
	course3.show();
	return 0;
}
