#include <stdio.h>

void swap(int *num, int *changenum); //swap�� ���� �Լ� ����

int main(void)
{
	char name[3][10]; //�л� �̸� ����
	int a, b, c; //��ȣ ���� (ù��° �л� ��ȣ, �ι�° �л� ��ȣ, �ٲ� ��ȣ)
	void(*pswap)(int *, int *); //pswap�� ���� �Լ� ����
	pswap = swap; //pswap�Լ��� swap�Լ��̴�

	printf("�̸��� �Է��ϼ��� : "); //ù��° �л� �̸� �Է�
	scanf("%s", name[0]);
	printf("��ȣ�� �Է��ϼ��� : "); //ù��° �л� ��ȣ �Է�
	scanf("%d", &a);

	printf("�̸��� �Է��ϼ��� : "); //�ι�° �л� �̸� �Է�
	scanf("%s", name[1]);
	printf("��ȣ�� �Է��ϼ��� : "); //�ι�° �л� ��ȣ �Է�
	scanf("%d", &b);

	printf("\n%s�� %d���̰�, %s�� %d���̴�.\n", name[0], a, name[1], b);

	printf("\n������ ��ȣ�� �ٲٽðڽ��ϱ�? "); //�ٲ� �л� �̸� �Է�
	scanf("%s", name[2]);
	printf("\n�ٲ� ��ȣ�� �Է��ϼ��� : "); //�ٲ� ��ȣ �Է�
	scanf("%d", &c);

	if (!strcmp(name[0], name[2])) //�ٲ� �л� �̸��� name1�� ������
	{
		pswap(&a, &c); //(p)swap�Լ� ȣ��
		printf("\n%s�� ��ȣ�� %d�� �ٲ�����ϴ�.\n", name[0], a);
	}

	else if (!strcmp(name[1], name[2])) //�ٲ� �л� �̸��� name2�� ������
	{
		pswap(&b, &c); //(p)swap�Լ� ȣ��
		printf("\n%s�� ��ȣ�� %d�� �ٲ�����ϴ�.\n", name[1], b);
	}

	else //name1�� name2�� �ƴ� ��
		printf("�߸� �Է��Ͽ����ϴ�.");
}

void swap(int *pnum, int *pchangenum) //�Լ� ����
{
	int hey;

	hey = *pnum; //hey�� num���� ����
	*pnum = *pchangenum; //num�� changenum���� ����
	*pchangenum = hey; //changenum�� hey�� ����
}