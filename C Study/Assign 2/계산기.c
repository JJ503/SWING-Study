#include<stdio.h>

int add(int x, int y); //덧셈 함수 선언
int sub(int x, int y); //뺄셈 함수 선언
int mul(int x, int y); //곱셈 함수 선언
int div(int x, int y); //나눗셈 함수 선언

int main()
{

	char i; //부호 변수
	int a; //첫번째 자리 변수
	int b; //두번째 자리 변수

	while (1) //무한루프
	{
		printf("연산을 입력하시오 : ");
		scanf("%d%c%d", &a, &i, &b); //첫번째 자리, 부호, 두번째 자리 입력

	switch (i)
	{
	case '+': //i가 +면 add 함수 호출
		printf("연산결과 : %d\n", add(a, b)); 
		break;

	case '-': //i가 -면 sub 함수 호출
		printf("연산결과 : %d\n", sub(a, b));
		break;

	case '*': //i가 *면 mul 함수 호출
		printf("연산결과 : %d\n", mul(a, b));
		break;
		 
	case '/': //i가 /면 div 함수 호출
		printf("연산결과 : %d\n", div(a, b));
		break;

	default: //i에 위같은 부호가 없으면 잘못 입력했음을 알려줌
		printf("잘못 입력하셨습니다\n");
		break;
	}
	}

}

int add(int x, int y) //add 함수 구현
{
	int re;
	re = x + y;
}

int sub(int x, int y) //sub 함수 구현
{
	int re;
	re = x - y;
}

int mul(int x, int y) //mul 함수 구현
{
	int re;
	re = x * y;
}

int div(int x, int y) //div 함수 구현
{
	int re;
	re = x / y;
}