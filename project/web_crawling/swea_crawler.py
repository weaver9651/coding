#-*- coding:utf-8 -*-
from selenium import webdriver
from bs4 import BeautifulSoup
import base64

login_id = "weaver9651@gmail.com"
login_pwd = "QHJsZHVmMTY0MzUy"

options = webdriver.ChromeOptions()
options.add_argument("headless")
options.add_argument("window-size=1920x1080")
options.add_argument("disable-gpu")

driver = webdriver.Chrome("/home/gykim/coding/project/web_crawling/chromedriver", chrome_options=options)
driver.implicitly_wait(3)
driver.get("https://swexpertacademy.com/main/sst/common/userTestList.do?")
driver.find_element_by_name("id").send_keys(login_id)
driver.find_element_by_name("pwd").send_keys(base64.b64decode(login_pwd))
driver.find_element_by_xpath('//*[@id="LoginForm"]/div/div/div[2]/div/div/fieldset/div/div[4]/button').click()
driver.implicitly_wait(3)
driver.find_element_by_xpath('/html/body/div[4]/div[1]/div/div/div[2]/div[2]/div/a').click()
driver.implicitly_wait(3)

html = driver.page_source
soup = BeautifulSoup(html, 'html.parser')
info = soup.find_all("td")
# body > div.sub-m > div:nth-child(9) > table > tbody > tr:nth-child(1) > td.status

# for i in range(1, 17):
#     j = i*(-1)
#     print info[j]

place1 = "삼성전자 인재개발원"
place2 = "SNU"
place1_status = info[-11]
place2_status = info[-16]

place1_status = str(place1_status)
place1_status = place1_status.split(">")[-2].split("\t")[0].strip()
place2_status = str(place2_status)
place2_status = place2_status.split(">")[-2].split("\t")[0].strip()

print place1, place1_status
print place2, place2_status

# driver.get_screenshot_as_file("test.png")

driver.quit()

