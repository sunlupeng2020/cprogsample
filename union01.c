#include<stdio.h>
struct date
{
    int year;
	int month;
	int day;
};
struct marriedState//���״̬
{
	struct date marryDay;
	char spouseName[20];//��ż����
	int child;
};
struct divorceState//����״̬
{
	struct date divorceDay;//�������
	int child;
};
union maritalState
{
    int single;//����
	struct marriedState married;//�ѻ�
	struct divorceState divorce;//���
};
struct person
{
	char name[20];//����
	char gender;//�Ա�
	int marryflag;//����״����0-δ�飬1-�ѻ飬2-����
	union maritalState marital;//����״��
};
void outputperson(struct person *p);//�������
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
void outputperson(struct person *p)//�������
{
	puts("������");
	puts(p->name);
	putchar('\n');
	puts("�Ա�");
	putchar(p->gender);
	putchar('\n');
	if(p->marryflag==0)
		printf("δ��\n");
	else if(p->marryflag==1)
	{
		printf("�ѻ�\n");
		printf("������ڣ�%d��%d��%d��\n",p->marital.married.marryDay.year,p->marital.married.marryDay.month,p->marital.married.marryDay.day);
		printf("��ż������%s\n",p->marital.married.spouseName);
		printf("��Ů������%d\n",p->marital.married.child);
	}
	else
	{
		printf("����\n");
		printf("������ڣ�%d��%d��%d��\n",p->marital.divorce.divorceDay.year,p->marital.divorce.divorceDay.month,p->marital.divorce.divorceDay.day);
		printf("��Ů������%d\n",p->marital.divorce.child);
	}
}