from bs4 import BeautifulSoup
import urllib.request

html = urllib.request.urlopen("https://www.swu.ac.kr/www/swuniversity.html")  # 서울여대 웹 페이지 요청
result = BeautifulSoup(html.read(), "html.parser")  # html의 관점에서 문자열 이해
search = result.findAll("a") # a태그의 정보 추출

print("*** 서울여자대학교 학과 및 홈페이지 정보 ***")
print("학과\t\t\t\t홈페이지")

for s in search:
    # 대학원이나 교육원이 들어가거나 자율전공학부와 공동기기실은 제외하기
    if "대학원" in s.text or "교육원" in s.text or "자율전공학부" == s.text or "공동기기실" == s.text:  
        continue

    else:
        dep_html = urllib.request.urlopen("https://www.swu.ac.kr" + s['href'])  # 해당 학과 페이지 요청
        dep_result = BeautifulSoup(dep_html.read(), "html.parser")  
        dep_search = dep_result.find("a", {"class", "btn btn_xl btn_blue_gray"})  # a태그 중 class가 btn btn_xl btn_blue_gray인 정보 추출 (학과 홈페이지)
    
        # 홈페이지가 없으면 "홈페이지가 존재하지 않음"이라 출력
        # bacha_28.html와 /www/bacha_28.html은 요람 바로가기 링크이므로 제외해주기
        if dep_search is None or dep_search['href'] == "bacha_28.html" or dep_search['href'] == "/www/bacha_28.html":
            print(s.text + "\t\t홈페이지가 존재하지 않음")

        # 학과 홈페이지가 있다면 학과명과 학과 홈페이지 주소 출력해주기
        else:
            print(s.text + "\t\t" + dep_search['href'])
