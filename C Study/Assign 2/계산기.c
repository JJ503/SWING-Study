#include<stdio.h>

int add(int x, int y); //���� �Լ� ����
int sub(int x, int y); //���� �Լ� ����
int mul(int x, int y); //���� �Լ� ����
int div(int x, int y); //������ �Լ� ����

int main()
{

	char i; //��ȣ ����
	int a; //ù��° �ڸ� ����
	int b; //�ι�° �ڸ� ����

	while (1) //���ѷ���
	{
		printf("������ �Է��Ͻÿ� : ");
		scanf("%d%c%d", &a, &i, &b); //ù��° �ڸ�, ��ȣ, �ι�° �ڸ� �Է�

	switch (i)
	{
	case '+': //i�� +�� add �Լ� ȣ��
		printf("������ : %d\n", add(a, b)); 
		break;

	case '-': //i�� -�� sub �Լ� ȣ��
		printf("������ : %d\n", sub(a, b));
		break;

	case '*': //i�� *�� mul �Լ� ȣ��
		printf("������ : %d\n", mul(a, b));
		break;
		 
	case '/': //i�� /�� div �Լ� ȣ��
		printf("������ : %d\n", div(a, b));
		break;

	default: //i�� ������ ��ȣ�� ������ �߸� �Է������� �˷���
		printf("�߸� �Է��ϼ̽��ϴ�\n");
		break;
	}
	}

}

int add(int x, int y) //add �Լ� ����
{
	int re;
	re = x + y;
}

int sub(int x, int y) //sub �Լ� ����
{
	int re;
	re = x - y;
}

int mul(int x, int y) //mul �Լ� ����
{
	int re;
	re = x * y;
}

int div(int x, int y) //div �Լ� ����
{
	int re;
	re = x / y;
}