#include<stdio.h>

int main()
{
	int a; //a는 정수
	int n; //한 줄에 쓰이는 숫자 개수
	int i; //횟수

	printf("정수를 입력하세요 : ");
	scanf("%d", &a); //a에 정수입력

	for (i = 1; i <= a; i++) //외부반복문 - 줄 횟수
	{
		for (n = 1; n <= i; n++) //내부반복문 - 한 줄에 쓰이는 숫자
		{
			printf("%d", n);
		}

		printf("\n"); //내부반복문이 끝날 때마다 실행
	}
}