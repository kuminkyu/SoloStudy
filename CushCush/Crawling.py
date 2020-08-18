from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.action_chains import ActionChains
import time
import re
import pandas as pd

from bs4 import BeautifulSoup
from urllib.request import urlopen

instagram_tags = []
instagram_tag_dates = []

plusUrl = input('검색할 태그를 입력하세요 : ')

driver = webdriver.Chrome()

driver.get('https://www.instagram.com/')
time.sleep(3)
elem = driver.find_element_by_name('username')
elem.send_keys('kuminkyu93@naver.com')
elem = driver.find_element_by_name('password')
elem.send_keys('tkfkd325!')
    
time.sleep(1)

#로그인 클릭 버튼
login_button = driver.find_element_by_xpath('/html/body/div/section/main/article/div[2]/div/div/form/div/div[3]/button')
login_button.click()
time.sleep(3)

#나중에 하기1
later_1 = driver.find_element_by_xpath('''//*[@id="react-root"]/section/main/div/div/div/div/button''')
later_1.click()
time.sleep(3)

#나중에 하기2
later_2 = driver.find_element_by_xpath('/html/body/div[4]/div/div/div/div[3]/button[2]')
later_2.click()
time.sleep(2)

#검색
search_1 = driver.find_element_by_xpath('/html/body/div/section/nav/div[2]/div/div/div[2]/input')
search_1.send_keys(plusUrl)
time.sleep(2)

#검색 엔터1
search_1.send_keys(Keys.ENTER)
time.sleep(2)

#검색 엔터2 (작동)
search_1.send_keys(Keys.ENTER)
time.sleep(2)

driver.find_element_by_css_selector('#react-root > section > main > article > div.EZdmt > div > div > div:nth-child(1)'
                                    ' > div:nth-child(1) > a > div > div._9AhH0').click()
time.sleep(2)

html = driver.page_source
soup = BeautifulSoup(html)

insta = soup.select('.v1Nh3.kIKUG._bz0w')

# https://velog.io/@codeamor/TIL-no.14-Python-%EC%9D%B8%EC%8A%A4%ED%83%80%EA%B7%B8%EB%9E%A8-%EC%9D%B4%EB%AF%B8%EC%A7%80-%ED%81%AC%EB%A1%A4%EB%A7%81

# 이미지 저장 
n = 1
for i in insta:
    print('https://www.instagram.com' + i.a['href'])
    imgUrl = i.select_one('.KL4Bh').img['src']
    with urlopen(imgUrl) as f:
        with open('./img/' + plusUrl + str(n) + '.jpg','wb') as h:
            img = f.read()
            h.write(img)
    n += 1

#크롤링 범위설정
for i in range(5):
    time.sleep(1)
    try:
        data = driver.find_element_by_css_selector('.C7I1f.X7jCj')  # C7I1f X7jCj  # 글이 있는 구역
        tag_raw = data.text
        
        tags = re.findall('#[A-Za-z0-9가-힣]+', tag_raw)
        tag = ''.join(tags).replace("#", " ")  # "#" 제거

        tag_data = tag.split()

        # id 저장
        instagram_tag_dates.append(i)

        for tag_one in tag_data:
            instagram_tags.append(tag_one)
        
        # body 안에 있는 태그 요소는 .text 로 추출할 수 있습니다. 
        # https://www.fun-coding.org/crawl_advance5.html
        # date 출력
        date = driver.find_element_by_xpath('/html/body/div[4]/div[2]/div/article/div[3]/div[2]/a/time')
        print(date.text)

        # User_ID 출력
        userid = driver.find_element_by_xpath('/html/body/div[4]/div[2]/div/article/div[3]/div[1]/ul/div/li/div/div/div[2]/h2/div/span/a')
        print(userid.text)   

        

    #print(instagram_tags)
   
    except:
        instagram_tags.append("error")

    try:
        WebDriverWait(driver, 100).until( #값을 불러올때까지 기다려줌 
            EC.presence_of_element_located((By.CSS_SELECTOR, '.C7I1f.X7jCj'))
        )
        driver.find_element_by_css_selector('body > div._2dDPU.CkGkG > div.EfHg9 > div > div '
                                            '> a._65Bje.coreSpriteRightPaginationArrow').click() # 다음 버튼
    except:
        driver.close()

    time.sleep(1)

print(instagram_tags)

#.txt파일로 저장
data = pd.DataFrame(instagram_tags)
data.to_csv('insta.txt', encoding='utf-8')