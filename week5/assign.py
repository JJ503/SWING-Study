from selenium import webdriver

driver = webdriver.Chrome('D:\Program\exe\chromedriver')  # chrome으로 열기
driver.get('http://zzzscore.com/1to50/')  # URL을 통해 게임 사이트 열기

# 첫 시도 -> 생각보다 느림
# count = 1 
# while count <= 50: 
#     i = 1
#     while i <= 25:
#         number = driver.find_element_by_xpath('//*[@id="grid"]/div[' + str(i) + ']')
#         i = i + 1
#         if str(count) == number.text:
#             number.click()
#             print("number  " + str(count) + " clicked!")
#             count = count + 1
#             break

# 두번째 시도 코드 -> 빨라짐!
count = 1
while count <= 50:
    number = driver.find_elements_by_xpath('//*[@id="grid"]/div[*]')
    for num in number:
        if num.text == str(count):
            num.click()
            print("number  " + str(count) + " clicked!")
            count += 1
            break

record = driver.find_element_by_xpath('//*[@id="result"]/div[2]/strong').text
print("\nrecord : " + record)
print(driver.find_element_by_xpath('//*[@id="result"]/div[2]/p[2]').text)
