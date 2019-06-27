from selenium import webdriver

login_id = "weaver9651@gmail.com"
login_pwd = "@rlduf164352"

options = webdriver.ChromeOptions()
options.add_argument("headless")
options.add_argument("window-size=1920x1080")
options.add_argument("disable-gpu")

driver = webdriver.Chrome("/home/gykim/coding/project/web_crawling/chromedriver", chrome_options=options)
driver.implicitly_wait(3)
driver.get("https://swexpertacademy.com/main/sst/common/userTestList.do?")
driver.find_element_by_name("id").send_keys(login_id)
driver.find_element_by_name("pwd").send_keys(login_pwd)

driver.get_screenshot_as_file("test.png")

driver.quit()

