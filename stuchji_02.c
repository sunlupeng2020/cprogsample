/*
*求一个学生的总分，学生有学号、姓名等信息，
*课程有语文、数学、英语三门.
*用指针实现。
*/
#include<stdio.h>
typedef struct Student Stu;
struct Student
{
    int num;//学号
	char name[20];//姓名
	int yuwen;//语文成绩
	int shuxue;//数学成绩
	int yingyu;//英语成绩
	int sum;//总分
};

int main()
{
	struct Student s={1001,"zeng",86,87,84,0};
	struct Student *p=&s;
	p->sum=p->yuwen+p->shuxue+p->yingyu;
	printf("学号：%d\n",p->num);
	printf("姓名：%s\n",p->name);
	printf("语文：%d\n",p->yuwen);
	printf("数学：%d\n",p->shuxue);
	printf("英语：%d\n",p->yingyu);
	printf("总分：%d\n",p->sum);
	return 0;
}
