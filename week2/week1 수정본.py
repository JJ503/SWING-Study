from random import *

rank = []   # 사용자들의 랭킹이 들어가는 리스트

while True:  # 게임을 무한 반복
    answer = randrange(1, 101)  # 답으로 정할 무작위 수
    start = 1   # 제시해주는 시작 수 -> 입력한 값이 n보다 크면 n을 satart로 지정
    end = 100   # 제시해주는 끝 수 -> 입력한 값이 n보다 작으면 n을 end로 지정

    print("\nUP & DOWN 게임에 오신걸 환영합니다~")  # 게임 시적
    print("1. 게임시작  2. 기록확인  3. 게임종료 ")
    select = input(">> ")   # 1, 2, 3 중 사용자가 하나 입력해 선택

    if select == "1":  # 1번 게임시작 선택
        num = 1   # 게임 횟수
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
                rank.sort()   # 있던 기록들을 정렬 시킴
                if not rank:  # 만약 rank 리스트가 비어있다면
                    print("최고기록 갱신!\n")  # 무조건 최고 기록임
                    rank.append(num)   # 게임 기록 rank 리스트에 넣기  -> 피드백 1번
                elif rank[0] > num:   # 만약 정렬된 rank 리스트에서 가장 작은 값인 rank[0]본다도 작은 수라면
                    print("최고기록 갱신!\n")  # 이번 게임의 기록이 최고기록임
                    rank.append(num)   # 게임 기록 rank 리스트에 넣기  -> 피드백 1번
                break      # 정답을 맞췄으니 break로 게임 반복문 탈출

            # 내가 적은 답이 실제 답보다 작다면
            elif myNumber >= start and myNumber < answer: 
                print("UP")       # 더 커야된다고 알려줌
                start = myNumber  # start 숫자를 입력한 숫자로 더 작은 숫자들은 입력 못하게 함
                num += 1          # 게임 한 번 진행

            # 내가 적은 답이 실제 답보다 크다면
            elif myNumber > answer and myNumber <= end:
                print("DOWN")     # 더 작아야된다고 알려줌
                end = myNumber    # end 숫자를 입력한 숫자로 바꿔 더 큰 수들을 입력 못하게 함
                num += 1          # 게임 한 번 진행 
            
            # 위의 경우가 아닌 경우 (start와 end 밖의 번호 입력)
            else:
                print("잘못 입력하셨습니다")  # 잘못 입력했다고 알려줌 그리고 n번째였다면 다시 n번째로 실행하기 위해 num에 +1 하지 않음

    elif select == "2":    # 만약 2번 기록확인 선택
        rank.sort()    # 리스트의 값들 정렬 (작은 수부터 순서대로)
        num = 1        # 등수 변수
        for i in rank: # 리스트의 요소 개수만큼 반복
            print("{0}등 : {1}번".format(num, i))  # 등수마다 몇번만에 맞췄는지 랭킹 보여줌
            num += 1   # 출력할 때마다 다음 등수로 등수 +1 해줌
    
    elif select == "3":   # 3번 게임종료 선택
        break  # break로 무한반복 중인 게임 탈출

    else :  # 1, 2, 3 이외의 것을 입력
        print("잘못 입력하셨습니다.\n")  # 잘못 입력했음을 알려줌
