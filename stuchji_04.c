/*
*求一个学生的总分，学生有学号、姓名等信息，
*课程有语文、数学、英语三门.
*用途：讲解在主函数中定义结构和数据类型。
*/
#include<stdio.h>
int main()
{
	typedef struct Student Student;
	struct Student
	{
		int num;//学号
		char name[20];//姓名
		int yuwen;//语文成绩
		int shuxue;//数学成绩
		int yingyu;//英语成绩
		int sum;//总分
	};

	struct Student s={1001,"zeng",86,87,84,0};
	s.sum=s.yuwen+s.shuxue+s.yingyu;
	printf("学号：%d\n",s.num);
	printf("姓名：%s\n",s.name);
	printf("语文：%d\n",s.yuwen);
	printf("数学：%d\n",s.shuxue);
	printf("英语：%d\n",s.yingyu);
	printf("总分：%d\n",s.sum);
	return 0;
}
