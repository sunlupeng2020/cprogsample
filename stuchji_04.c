/*
*��һ��ѧ�����ܷ֣�ѧ����ѧ�š���������Ϣ��
*�γ������ġ���ѧ��Ӣ������.
*��;���������������ж���ṹ���������͡�
*/
#include<stdio.h>
int main()
{
	typedef struct Student Student;
	struct Student
	{
		int num;//ѧ��
		char name[20];//����
		int yuwen;//���ĳɼ�
		int shuxue;//��ѧ�ɼ�
		int yingyu;//Ӣ��ɼ�
		int sum;//�ܷ�
	};

	struct Student s={1001,"zeng",86,87,84,0};
	s.sum=s.yuwen+s.shuxue+s.yingyu;
	printf("ѧ�ţ�%d\n",s.num);
	printf("������%s\n",s.name);
	printf("���ģ�%d\n",s.yuwen);
	printf("��ѧ��%d\n",s.shuxue);
	printf("Ӣ�%d\n",s.yingyu);
	printf("�ܷ֣�%d\n",s.sum);
	return 0;
}
