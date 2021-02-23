#include<stdio.h>
struct date
{
    int year;
	int month;
	int day;
};
struct marriedState//结婚状态
{
	struct date marryDay;
	char spouseName[20];//配偶姓名
	int child;
};
struct divorceState//离异状态
{
	struct date divorceDay;//离婚日期
	int child;
};
union maritalState
{
    int single;//单身
	struct marriedState married;//已婚
	struct divorceState divorce;//离婚
};
struct person
{
	char name[20];//姓名
	char gender;//性别
	int marryflag;//婚姻状况，0-未婚，1-已婚，2-离异
	union maritalState marital;//婚姻状况
};
void outputperson(struct person *p);//输出数据
int main()
{
	struct person p1;
	scanf("%s",p1.name);
	scanf("%c",&p1.gender);
	scanf("%d",&p1.marryflag);
	if(p1.marryflag==0)
		p1.marital.single =1;
	else if(p1.marryflag==1)
	{
		scanf("%d",&p1.marital.married.marryDay.year);
		scanf("%d",&p1.marital.married.marryDay.month);
		scanf("%d",&p1.marital.married.marryDay.day);
		scanf("%s",p1.marital.married.spouseName);
		scanf("%d",p1.marital.married.child);
	}
	else
	{
		scanf("%d",&p1.marital.divorce.divorceDay.year);
		scanf("%d",&p1.marital.divorce.divorceDay.month);
		scanf("%d",&p1.marital.divorce.divorceDay.day);
		scanf("%d",p1.marital.divorce.child);
	}
	outputperson(&p1);
	return 0;
}
void outputperson(struct person *p)//输出数据
{
	puts("姓名：");
	puts(p->name);
	putchar('\n');
	puts("性别：");
	putchar(p->gender);
	putchar('\n');
	if(p->marryflag==0)
		printf("未婚\n");
	else if(p->marryflag==1)
	{
		printf("已婚\n");
		printf("结婚日期：%d年%d月%d日\n",p->marital.married.marryDay.year,p->marital.married.marryDay.month,p->marital.married.marryDay.day);
		printf("配偶姓名：%s\n",p->marital.married.spouseName);
		printf("子女数量：%d\n",p->marital.married.child);
	}
	else
	{
		printf("离异\n");
		printf("离婚日期：%d年%d月%d日\n",p->marital.divorce.divorceDay.year,p->marital.divorce.divorceDay.month,p->marital.divorce.divorceDay.day);
		printf("子女数量：%d\n",p->marital.divorce.child);
	}
}