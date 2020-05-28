# 웹툰 최신화 한 화만 이미지 

# 필요한 모듈들 가져오기
import os 
from bs4 import BeautifulSoup  
import urllib.request

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

newEpi = result.find("td", {"class", "title"})  # 웹툰 에피소드 하나의 url찾기 (한 화만 가져오므로 findAll이 아닌 find로 하나만 찾기)

newEpi_html = urllib.request.urlopen("https://comic.naver.com" + newEpi.a['href']) # 원하는 에피소드 주소로 요청하기
newEpi_result = BeautifulSoup(newEpi_html.read(), "html.parser") # 요청한 웹 페이지 파싱하기

img = newEpi_result.find("div", {"class", "wt_viewer"}) # div의 class가 wt_viewer인 가장 첫번째가 웹툰 이미지 영역임
imgUrl = img.findAll("img")  # class가 wt_viewer인 영역에서 img만 모두 가져오기 -> 웹툰 이미지

# 네이버와 같은 사이트에서는 크롤링을 통해 정보를 빼오는 것이 봇인지 판별한다
# 그렇기에 사람인 것처럼 속이기 위해 아래와 같은 코드를 사용한다
opener = urllib.request.build_opener()
opener.addheaders=[('User-Agent','Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/36.0.1941.0 Safari/537.36')]
urllib.request.install_opener(opener)

num = 1  # 이미지 이름 변수
for url in imgUrl:  # 찾은 imgUrl이 있을 때까지 반복
    save = str(num) + ".jpg"  # 이미지 이름 + 확장자명 하나로 저장
    urllib.request.urlretrieve(url.get("src"), save)  # 이미지 url을 통해 다운로드
    print(str(num) + "번째 이미지 저장 성공")  # 성공했다는 의미의 문자열 출력
    num = num + 1  # 이미지 이름 + 1

print("이미지 저장 완료")  # 이미지 다운로드가 모두 완료되면 완료했다는 문자열 출력
