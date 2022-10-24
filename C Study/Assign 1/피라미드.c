#include <stdio.h>

int main()
{
	int h; //피라미드의 높이
	int n; //현재 층
	int b; //공백과 *의 개수

	printf("출력할 피라미드의 높이를 입력하세요 >> "); //피라미드 층 수 입력
	scanf("%d", &h);

	for (n = 0; n < h; n++)  //외부 반복문 - 층 수 만큼 반복
	{
		for (b = 0; b < h - n; b++) //내부 반복문1 - 한 층에 들어가는 ' '
		{
			printf(" ");
		}
		
		for (b = 0; b < 2 * n + 1; b++) //내부 반복문2 - 한 층에 들어가는 '*'
		{
			printf("*");
		}
		
		printf("\n"); //층 바꾸기
	}
}