from random import *
import re    #정규 표현식
import os

if not os.path.isfile("rank.txt"):
    f = open("rank.txt", 'w')
    f.close()


def game():
    num = 1   # 게임 횟수
    answer = randrange(1, 101)  # 답으로 정할 무작위 수
    start = 1   # 제시해주는 시작 수 -> 입력한 값이 n보다 크면 n을 satart로 지정
    end = 100   # 제시해주는 끝 수 -> 입력한 값이 n보다 작으면 n을 end로 지정

    print(answer)

    while True:  # UP & DOWN 무한반복
        if num == 11:  # 10번의 기회만 제공하기 위한 조건문
            print("입력횟수를 초과하였습니다. 게임오버!")
            break  # 11번째엔 실행하지 않고 break로 반복문 탈출

        print("\n{0}번째 숫자 입력({1} ~ {2})".format(num, start, end))  # 사용자가 start와 end 값을 보고
        myNumber = int(input(">> "))                                    # 정답으로 생각하는 숫자를 입력해 줌
            
        # 정답
        if myNumber == answer: 
            print("정답이니다!!")      # 정답임을 알려줌
            print("{0}번째만에 맞추셨습니다.".format(num))  # 몇 번만에 맞췄는지 알려줌

            with open("rank.txt", 'r') as rank_file: # with는 file을 연후 with를 빠져나가면 자동 file.close()
                ranker = rank_file.readlines()   # txt파일에 있는 글 전체 불러오기
            
            if not ranker:  # 만약 rank 리스트가 비어있다면
                with open("rank.txt", 'a') as rank_file: # with는 file을 연후 with를 빠져나가면 자동 file.close()
                    print("aaa")
                    print("최고기록 갱신!\n")  # 무조건 최고 기록임
                    name = input("이름을 입력해주세요 >>")
                    rank_file.write("{0} {1}회\n".format(name, num))   # 게임 기록 rank 파일에 넣기

            else :   # 만약 정렬된 rank 리스트에서 가장 작은 값인 rank[0]본다도 작은 수라면
                rank_list = list(re.findall('\d+', ranker[0]))  # 읽은 줄에서 숫자만 골라내기
                rank_num = int(rank_list[-1])    # 1등 줄의 숫자들 중 가장 마지막이 게임 횟수 (등수와 이름이 숫자이기 때문)

                if rank_num > num :
                    print("최고기록 갱신!\n")  # 이번 게임의 기록이 최고기록임
                    name = input("이름을 입력해주세요 >> ")
                    with open("rank.txt", 'w') as rank_file:
                        #new_ranker = name + " " + str(num) + "회"
                        rank_file.write("{0} {1}회\n".format(name, num))   # 게임 기록 rank 파일에 넣기

                    with open("rank.txt", 'a') as rank_file:
                        for rankers in ranker:
                            rank_file.write(rankers)
                    
            break      # 정답을 맞췄으니 break로 게임 반복문 탈출

        # 내가 적은 답이 실제 답보다 작다면
        elif myNumber >= start and myNumber < answer: 
            print("UP")       # 더 커야된다고 알려줌
            start = myNumber + 1  # start 숫자를 입력한 숫자 + 1로 더 작은 숫자들은 입력 못하게 함
            num += 1          # 게임 한 번 진행

        # 내가 적은 답이 실제 답보다 크다면
        elif myNumber > answer and myNumber <= end:
            print("DOWN")     # 더 작아야된다고 알려줌
            end = myNumber - 1    # end 숫자를 입력한 숫자 - 1로 바꿔 더 큰 수들을 입력 못하게 함
            num += 1          # 게임 한 번 진행 
            
        # 위의 경우가 아닌 경우 (start와 end 밖의 번호 입력)
        else:
            print("잘못 입력하셨습니다")  # 잘못 입력했다고 알려줌 그리고 n번째였다면 다시 n번째로 실행하기 위해 num에 +1 하지 않음

def rank():
    num = 1       # 등수 변수
    print("rank/name/score\n")
    with open("rank.txt", 'r') as rank_file: # with는 file을 연후 with를 빠져나가면 자동 file.close()
        while True:
            line = rank_file.readline()   # txt파일에 있는 글을 한 줄씩 읽기
            if not line: break    # 글이 없다면 break

            print("{0}등 {1}".format(num, line), end="") # 등수마다 몇번만에 맞췄는지 랭킹 보여줌
            num += 1   # 출력할 때마다 다음 등수로 등수 +1 해줌



# main 코드
while True:  # 게임을 무한 반복
    print("\nUP & DOWN 게임에 오신걸 환영합니다~")  # 게임 시적
    print("1. 게임시작  2. 기록확인  3. 게임종료 ")
    select = input(">> ")   # 1, 2, 3 중 사용자가 하나 입력해 선택

    if select == "1":  # 1번 게임시작 선택
        game()

    elif select == "2":    # 만약 2번 기록확인 선택
        rank()
    
    elif select == "3":   # 3번 게임종료 선택
        print("게임이 종료되었습니다.")
        break  # break로 무한반복 중인 게임 탈출

    else :  # 1, 2, 3 이외의 것을 입력
        print("잘못 입력하셨습니다.\n")  # 잘못 입력했음을 알려줌
