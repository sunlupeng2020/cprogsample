/*
*��һ��ѧ�����ܷ֣�ѧ����ѧ�š���������Ϣ��
*�γ������ġ���ѧ��Ӣ������.
*��ָ��ʵ�֡�
*�ú���ʵ�����ܷ֡�
*/
#include<stdio.h>
typedef struct Student Stu;
struct Student
{
    int num;//ѧ��
	char name[20];//����
	int yuwen;//���ĳɼ�
	int shuxue;//��ѧ�ɼ�
	int yingyu;//Ӣ��ɼ�
	int sum;//�ܷ�
};
void getSum(struct Student *ps);
int main()
{
	struct Student s={1001,"zeng",86,87,84,0};
	struct Student *p=&s;
	getSum(p);
	printf("ѧ�ţ�%d\n",p->num);
	printf("������%s\n",p->name);
	printf("���ģ�%d\n",p->yuwen);
	printf("��ѧ��%d\n",p->shuxue);
	printf("Ӣ�%d\n",p->yingyu);
	printf("�ܷ֣�%d\n",p->sum);
	return 0;
}
void getSum(struct Student *p)
{
	p->sum = p->yuwen + p->shuxue + p->yingyu;
}