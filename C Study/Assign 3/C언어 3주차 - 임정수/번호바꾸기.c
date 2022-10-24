#include <stdio.h>

void swap(int *num, int *changenum); //swap에 대한 함수 선언

int main(void)
{
	char name[3][10]; //학생 이름 변수
	int a, b, c; //번호 변수 (첫번째 학생 번호, 두번째 학생 번호, 바꿀 번호)
	void(*pswap)(int *, int *); //pswap에 대한 함수 선언
	pswap = swap; //pswap함수는 swap함수이다

	printf("이름을 입력하세요 : "); //첫번째 학생 이름 입력
	scanf("%s", name[0]);
	printf("번호를 입력하세요 : "); //첫번째 학생 번호 입력
	scanf("%d", &a);

	printf("이름을 입력하세요 : "); //두번째 학생 이름 입력
	scanf("%s", name[1]);
	printf("번호를 입력하세요 : "); //두번째 학생 번호 입력
	scanf("%d", &b);

	printf("\n%s는 %d번이고, %s는 %d번이다.\n", name[0], a, name[1], b);

	printf("\n누구의 번호를 바꾸시겠습니까? "); //바꿀 학생 이름 입력
	scanf("%s", name[2]);
	printf("\n바꿀 번호를 입력하세요 : "); //바꿀 번호 입력
	scanf("%d", &c);

	if (!strcmp(name[0], name[2])) //바꿀 학생 이름이 name1과 같으면
	{
		pswap(&a, &c); //(p)swap함수 호출
		printf("\n%s의 번호는 %d로 바뀌었습니다.\n", name[0], a);
	}

	else if (!strcmp(name[1], name[2])) //바꿀 학생 이름이 name2와 같으면
	{
		pswap(&b, &c); //(p)swap함수 호출
		printf("\n%s의 번호는 %d로 바뀌었습니다.\n", name[1], b);
	}

	else //name1도 name2도 아닐 때
		printf("잘못 입력하였습니다.");
}

void swap(int *pnum, int *pchangenum) //함수 구현
{
	int hey;

	hey = *pnum; //hey를 num으로 변경
	*pnum = *pchangenum; //num을 changenum으로 변경
	*pchangenum = hey; //changenum을 hey로 변경
}