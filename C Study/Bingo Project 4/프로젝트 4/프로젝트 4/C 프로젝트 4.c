#include <stdio.h>
#include <stdlib.h> //동적메모리를 관리 함수
#include <string.h> //문자열 처리 함수
#include <time.h> //시간 얻어 그 시간에 맞는 랜덤값 출력
#include <windows.h> //윈도우API의 함수를 위한 헤더 파일

int main()
{
	struct bingo //빙고에 관한 구조체
	{
		char user[10]; //사용자 이름
		char test[25]; //테스트용 1차 배열
		char bingo[5][5]; //빙고판을 만드는 2차 배열
		int Bingo; //빙고 개수
		int check[12]; //빙고 확인 (0~4는 가로, 5~9는 세로, 10~11은 대각선)
	};

	int num; //사람수
	int i, k, j, h, s, l; //반복문을 위한 변수
	int t; //2차원 배열에서 다음 줄로 넘어가는 것을 위한 변수
	struct bingo *p; //포인터를 이용한 구조체
	char ch[25];

	printf("게임을 할 사람 수 : "); //게임 할 사람 수 num에 입력 
	scanf("%d", &num);

	p = (struct bingo *)malloc(sizeof(struct bingo) * num); //p를 num만큼의 struct사이즈로 지정


	for (k = 0; k < num; k++)
	{
		printf("%d번의 player이름을 입력해 주세요 : ", k + 1);
		scanf("%s", (p + k)->user);  //p + k struct user에 이름 넣기
	}

	system("cls"); //화면 지우기

	srand(time(NULL)); //시간에 따른 랜덤값

	for (k = 0; k < num; k++) //외부반복문 - 사람 수만큼 반복
	{
		for (i = 0; i < 25; i++) //내부반복문(1) - A ~ Y까지 이므로 25번 반복
		{
			(p + k)->test[i] = rand() % 25 + 65; //p + k번 사람의 test에 A ~ Y까지 랜덤으로 중복 없이 입력

			for (j = 0; j < i; j++) //내부반복문(2) - 현재 i와 
			{
				if ((p + k)->test[i] == (p + k)->test[j]) //앞에 중복이 있는지 확인
				{
					i--; //있으면 i를 -1해서 다시 랜덤값 지정하기
					break;
				}
			}
		}
	}

	for (k = 0; k < num; k++) //외부반복문 - 사람 수만큼 반복
	{
		t = 0; //t값 초기화

		for (i = 0; i < 5; i++) //내부반복문(1) - 빙고의 세로
		{
			for (j = 0; j < 5; j++) //내부반복문(2) - 빙고의 가로
			{
				(p + k)->bingo[i][j] = (p + k)->test[j + t]; //test에서 5개씩 빙고에 한줄씩 넣기 
			}

			t = t + 5; //t는 내부반복문(2)가 끝날 때 마다 5씩 더하기
		}
	}

	for (k = 0; k < num; k++) //게임 참여자 이름 명수만큼 출력
	{
		printf("%15s            ", (p + k)->user);
	}

	printf("\n");

	for (i = 0; i < 5; i++) //외부반복문 - 다음 줄로 바꾸기
	{
		printf("   ");

		for (k = 0; k < num; k++) //내부반복문(1) - 5개씩 출력을 사람당 할 수 있게 만들어줌 (가로로 나타내기 위해)
		{
			for (j = 0; j < 5; j++) //내부반복문(2) - 사람당 5개씩 출력
			{
				printf("%c   ", (p + k)->bingo[i][j]); //빙고판 출력
			}
			if (k < num - 1) //마지막 사람에게 |이 안보이게 하기 위해 if로 마지막에는 |출력이 안되게 만들어줌
				printf("  |    ");
		}
		printf("\n"); //줄 바꿈 (enter)
	}

	for (l = 0; ; l++) //외부반복문 - 무한반복
	{
		h = 1; //사람명수번 할 때마다 다시 user1으로 만들어주기

		for (; h < num + 1; h++) //내부반복문 - 사람 명수번 실행하기
		{
			for (k = 0; k < num; k++)
			{
				if ((p + k)->Bingo == 3) //빙고가 3개면 누가 이겼는지 알려주고 끝내기
				{
					printf("\n%s 이(가) 이겼습니다\n\n", (p + k)->user);
					system("pause");
				}
			}

			printf("\%s 알파벳을 입력해주세요 : ", (p + h - 1)->user); //알파벳 선택
			scanf(" %c", &ch[l]);

			if (ch[l] < 'A' || ch[l] > 'Z') //A와 Z 밖이면 잘못 입력했다고 알려줌
			{
				printf("잘못 입력하셨습니다.\n");
				h--;
				continue; //다시 실행
			}

			for (k = 0; k < num; k++) //외부반복문 - 사람 수만큼 반복
			{
				t = 0; //t값 초기화

				for (i = 0; i < 5; i++) //내부반복문(1) - 빙고의 세로
				{
					for (j = 0; j < 5; j++) //내부반복문(2) - 빙고의 가로
					{
						if ((p + k)->bingo[i][j] == ch[l]) //선택한 알파벳과 같은 알파벳은 #으로 바꾸기
							(p + k)->bingo[i][j] = '#';
					}

					t = t + 5; //t는 내부반복문(2)가 끝날 때 마다 5씩 더하기
				}
			}

			for (i = 0; i < num; i++)
			{
				(p + i)->Bingo = 0;

				for (k = 0; k < 12; k++)
				{
					(p + i)->check[k] = 0;
				}
			}

			for (i = 0; i < num; i++) //외부반복문 - 빙고 확인
			{
				for (k = 0; k < 5; k++) //내부반복문 - 가로, 세로 확인
				{
					for (j = 0; j < 5; j++)
					{
						if ((p + i)->bingo[k][j] == '#') //가로 #인지 확인
						{
							(p + i)->check[k]++; //#이면 check에 +1
						}

						if ((p + i)->bingo[j][k] == '#') //세로 #인지 확인
						{
							(p + i)->check[k + 5]++; //#이면 check에 +1
						}
					}

					if ((p + i)->bingo[k][k] == '#') //대각선 중 [0][0]부터 빙고인 줄 확인
					{
						(p + i)->check[10]++; //#이면 check에 +1
					}


					if ((p + i)->bingo[k][4 - k] == '#') //대각선 중 [0][4]부터 빙고인 줄 확인
					{
						(p + i)->check[11]++; //#이면 check에 +1
					}
				}

				for (k = 0; k < 12; k++) //내부반복문 - check 확인
				{
					if ((p + i)->check[k] == 5) //#이 5개로 빙고인지 확인
					{
						(p + i)->Bingo++;
					}
				}
			}

			system("cls"); //화면 지우기

			for (k = 0; k < num; k++) //게임 참여자 이름 명수만큼 출력
			{
				printf("%10s 빙고 %d개        ", (p + k)->user, (p + k)->Bingo);
			}

			printf("\n");

			for (i = 0; i < 5; i++) //외부반복문 - 다음 줄로 바꾸기
			{
				printf("   ");

				for (k = 0; k < num; k++) //내부반복문(1) - 5개씩 출력을 사람당 할 수 있게 만들어줌 (가로로 나타내기 위해)
				{
					for (j = 0; j < 5; j++) //내부반복문(2) - 사람당 5개씩 출력
					{
						printf("%c   ", (p + k)->bingo[i][j]); //빙고판 출력
					}
					if (k < num - 1) //마지막 사람에게 |이 안보이게 하기 위해 if로 마지막에는 |출력이 안되게 만들어줌
						printf("  |    ");
				}

				printf("\n"); //줄 바꾸기
			}
		}
	}
}