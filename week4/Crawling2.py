# 웹툰 최신 10 화 이미지

# 필요한 모듈들 가져오기
import os
from bs4 import BeautifulSoup
import urllib.request


opener = urllib.request.build_opener()
opener.addheaders=[('User-Agent','Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/36.0.1941.0 Safari/537.36')]
urllib.request.install_opener(opener)

# 크롤링할 웹툰 선택해 주소로 웹 페이지 요청
html = urllib.request.urlopen("https://comic.naver.com/webtoon/list.nhn?titleId=694946&weekday=mon")
result = BeautifulSoup(html.read(), "html.parser")  # 요청한 웹 페이지 파싱
# 웹툰 이름 불러오기  split()하면 리스트에 웹툰 이름과 QTT가 저장됨 그중 [0]이 웹툰 제목
name = result.find("div", {"class", "detail"}).find("h2").text.split()[0]

# 파일을 저장하고 싶은 경로로 이동하기
os.chdir("week 4")
path = os.getcwd()
if not os.path.isdir(name): # 만약 만들려는 폴더 (웹툰 제목인 폴더)가 없다면 폴더 생성
    os.mkdir(name)
os.chdir(name)  # 만든(혹은 만들어진) 폴더로 경로 이동

newEpi = result.findAll("td", {"class", "title"})  # 웹툰 에피소드 하나의 url찾기 (첫 페이지의 최신 10화를 가져오므로 모두 가져와야 함 -> findAll 사용)

# 화마다 해당 화 제목으로 파일 생성후 경로 이동 (첫 페이지에 있는 화수가 끝날 때 까지 반복)
for epi in newEpi:
    epi_title = epi.text.split("\n")[1]  # 해당 화의 제목 가져오기
    if not os.path.isdir(epi_title):  # 제목으로 만들어진 폴더가 있는지 확인 후 없으면 폴더 생성
        os.mkdir(epi_title)

    os.chdir(epi_title)  # 만든(혹은 만들어져 있던) 폴더로 경로 이동

    epi_html = urllib.request.urlopen("https://comic.naver.com" + epi.a['href'])  # 해당 화 주소로 웹 페이지 요청
    epi_result = BeautifulSoup(epi_html.read(), "html.parser")  # 요청한 웹 페이지 파싱

    img = epi_result.find("div", {"class", "wt_viewer"}) # div의 class가 wt_viewer인 가장 첫번째가 웹툰 이미지 영역임
    imgUrl = img.findAll("img")  # class가 wt_viewer에서 img만 빼오기 -> 웹툰 이미지

    num = 1  # 이미지 이름 변수
    print(epi_title + " 이미지 저장 시작")  # 해당 화 웹툰 이미지 다운로드 시작을 알림
    for url in imgUrl:  # 해당 화에 웹툰 이미지가 없어질 때까지 반복
        save = str(num) + ".jpg"  # 이미지 이름 + 확장자명 하나로 저장
        urllib.request.urlretrieve(url.get("src"), save)  # 이미지 url을 통해 다운로드
        print(str(num) + "번째 이미지 저장 성공")  # 성공했다는 의미의 문자열 출력
        num = num + 1  # 이미지 이름 + 1
    
    print(epi_title + " 이미지 저장 완료\n\n")  # 해당 화 웹툰 이미지 다운로드 완료를 알림
    os.chdir("..")  # 다음 화의 폴더로 이동하기 위해 현재 경로에서 이전 디렉토리로 이동

print("모든 이미지 저장 완료")
