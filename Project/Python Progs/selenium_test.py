import unittest
import time
import HtmlTestRunner
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.select import Select


class TheSparksFoundation(unittest.TestCase):
    
    # Setup the selenium driver to control the browser by the Robot.
    def setUp(self):
        self.driver = webdriver.Firefox()
        self.driver.maximize_window()

        url = "https://www.thesparksfoundationsingapore.org/"
        self.driver.get(url)


    # Test the Title of the website.
    def test_01_verify_title(self):
        self.driver.find_element(By.XPATH, '//*[@id="home"]/div/div[1]/h1/a').click()
        assert True


    # Test the Logo the website.
    def test_02_verify_logo(self):
        self.driver.find_element(By.CLASS_NAME, 'navbar-brand')
        assert True


    # Test the NavBar of the website.
    def test_03_verify_navbar(self):
        self.driver.find_element(By.XPATH, '//*[@id="home"]/div/div[1]')
        assert True


    # Test to Verify About Us page.
    def test_04_verify_AboutUs_page(self):
        self.driver.find_element(By.XPATH,'//*[@id="link-effect-3"]/ul/li[1]/a').click()
        time.sleep(2)

        elements = self.driver.find_elements(By.XPATH, '//*[@id="link-effect-3"]/ul/li[1]/ul')

        # Collect all the elements present in the About Us drop down menu.
        elm_list = []
        for element in elements:
            elm_list.append(element.text.split('\n'))

        elm_list = elm_list[0]

        # Navigate through all the links present in the About Us drop down menu.
        for elm in elm_list:
            self.driver.find_element(By.LINK_TEXT, f'{elm}').click()
            time.sleep(3)

            self.driver.find_element(By.XPATH,'//*[@id="link-effect-3"]/ul/li[1]/a').click()
            time.sleep(2)
        
        assert True


    # Test to verify Policies and Code page.
    def test_05_verify_Policies_and_Code_page(self):
        self.driver.find_element(By.XPATH, '//*[@id="link-effect-3"]/ul/li[2]/a').click()
        time.sleep(2)

        elements = self.driver.find_elements(By.XPATH, '//*[@id="link-effect-3"]/ul/li[2]/ul')

        # Collect all the elements present in the Policies and Code drop down menu.
        elm_list = []
        for element in elements:
            elm_list.append(element.text.split('\n'))

        elm_list = elm_list[0]

        # Navigate through all the links present in the Policies and Code drop down menu.
        for elm in elm_list:
            self.driver.find_element(By.LINK_TEXT, f'{elm}').click()
            time.sleep(3)

            self.driver.find_element(By.XPATH, '//*[@id="link-effect-3"]/ul/li[2]/a').click()
            time.sleep(2)
        
        assert True


    # Test to verify Programs page.
    def test_06_verify_Programs_page(self):
        self.driver.find_element(By.XPATH, '//*[@id="link-effect-3"]/ul/li[3]/a').click()
        time.sleep(2)

        elements = self.driver.find_elements(By.XPATH, '//*[@id="link-effect-3"]/ul/li[3]/ul')

        # Collect all the elements present in the Programs drop down menu.
        elm_list = []
        for element in elements:
            elm_list.append(element.text.split('\n'))

        elm_list = elm_list[0]

        # Navigate through all the links present in the Programs drop down menu.
        for elm in elm_list:
            self.driver.find_element(By.LINK_TEXT, f'{elm}').click()
            time.sleep(3)

            self.driver.find_element(By.XPATH, '//*[@id="link-effect-3"]/ul/li[3]/a').click()
            time.sleep(2)
        
        assert True


    # Test to verify Links page.
    def test_07_verify_Links_page(self):
        self.driver.find_element(By.XPATH, '//*[@id="link-effect-3"]/ul/li[4]/a').click()
        time.sleep(2)

        elements = self.driver.find_elements(By.XPATH, '//*[@id="link-effect-3"]/ul/li[4]/ul')

        # Collect all the elements present in the Links drop down menu.
        elm_list = []
        for element in elements:
            elm_list.append(element.text.split('\n'))

        elm_list = elm_list[0]

        # Navigate through all the links present in the Links drop down menu.
        for elm in elm_list:
            self.driver.find_element(By.LINK_TEXT, f'{elm}').click()
            time.sleep(3)

            self.driver.find_element(By.XPATH, '//*[@id="link-effect-3"]/ul/li[4]/a').click()
            time.sleep(2)
        
        assert True
    

    # Test to verify Join Us page.
    def test_08_verify_JoinUs_page(self):
        self.driver.find_element(By.XPATH, '//*[@id="link-effect-3"]/ul/li[5]/a').click()
        time.sleep(2)

        elements = self.driver.find_elements(By.XPATH, '//*[@id="link-effect-3"]/ul/li[5]/ul')

        # Collect all the elements present in the Join Us drop down menu.
        elm_list = []
        for element in elements:
            elm_list.append(element.text.split('\n'))

        elm_list = elm_list[0]

        # Navigate through all the links present in the Join Us drop down menu.
        for elm in elm_list:
            self.driver.find_element(By.LINK_TEXT, f'{elm}').click()
            time.sleep(3)

            self.driver.find_element(By.XPATH, '//*[@id="link-effect-3"]/ul/li[5]/a').click()
            time.sleep(2)
        
        assert True


    # Test to verify Contact Us page.
    def test_09_verify_ContactUs_page(self):
        self.driver.find_element(By.XPATH, '//*[@id="link-effect-3"]/ul/li[6]/a').click()
        time.sleep(3)

        assert True


    # Test to verify Join Us Form Fillup.
    def test_10_Fill_JoinUs_Form(self):
        self.driver.find_element(By.XPATH,'//*[@id="link-effect-3"]/ul/li[5]/a').click()
        time.sleep(2)

        self.driver.find_element(By.XPATH,'//*[@id="link-effect-3"]/ul/li[5]/ul/li[1]/a').click()
        time.sleep(2)

        # Window scroll down the web page to a specified height.
        self.driver.execute_script("window.scrollTo(0, 800)")
        time.sleep(3)

        # Robot enter the details in the input form.
        name = self.driver.find_element(By.NAME, 'Name')
        name.send_keys("Akash Das")
        time.sleep(2)

        email_or_phone = self.driver.find_element(By.NAME, 'Email')
        email_or_phone.send_keys("das88764@gmail.com")
        time.sleep(2)

        # Selects options from the drop down menu in the form.
        option = Select(self.driver.find_element(By.CLASS_NAME, 'form-control'))
        option.select_by_visible_text('Intern')
        time.sleep(2)

        self.driver.find_element(By.CLASS_NAME, 'button-w3layouts').click()
        time.sleep(4)

        assert True


    # Test the Know More button in the home page.
    def test_11_KnowMore_btn(self):
        self.driver.execute_script("window.scrollTo(0, 450)")
        time.sleep(2)

        self.driver.find_element(By.XPATH, '/html/body/div[2]/div/div[2]/a').click()
        time.sleep(2)

        assert True


    # Test the Learn More button in the home page.
    def test_12_LearnMore_btn(self):
        self.driver.execute_script("window.scrollTo(0, 1000)")
        time.sleep(3)

        self.driver.find_element(By.XPATH, '/html/body/div[3]/div[2]/div/a').click()
        time.sleep(2)

        assert True


    # Test the Visit Now button in the home page.
    def test_13_VisitNow_btn(self):

        # Scroll down to the visit Now button in the home page.
        self.driver.execute_script("window.scrollTo(0, 1500)")
        time.sleep(3)
        
        # Fetch the url from the visit now button.
        visit_now_url = self.driver.find_element(By.XPATH, '/html/body/div[4]/div/div[1]/a').get_attribute('href')
        time.sleep(2)

        # Open a new tab
        self.driver.execute_script("window.open('');")
  
        # Switch to the new tab and open the new URL
        self.driver.switch_to.window(self.driver.window_handles[1])
        self.driver.get(visit_now_url)
        time.sleep(5)

        # Close the new tab.
        self.driver.close()

        # again switch to the main tab.
        self.driver.switch_to.window(self.driver.window_handles[0])
        time.sleep(2)

        assert True


    # Test all the Explore buttons in the home page.
    def test_14_Explore_btn(self):

        # Scroll down the web page to a specified height.
        self.driver.execute_script("window.scrollTo(0, 2000)")
        time.sleep(2)

        # Store the elements of the explore buttons.
        items = self.driver.find_elements(By.CLASS_NAME, 'owl-item')

        # Loops through the Corporate partner's Explore buttons.
        for item in items:
            new_url = item.find_element(By.TAG_NAME, 'a').get_attribute('href')

            # Open a new tab
            self.driver.execute_script("window.open('');")
    
            # Switch to the new tab and open the new URL
            self.driver.switch_to.window(self.driver.window_handles[1])
            self.driver.get(new_url)
            time.sleep(5)

            # Close the new tab.
            self.driver.close()

            # again switch to the main tab.
            self.driver.switch_to.window(self.driver.window_handles[0])
            time.sleep(2)

        assert True    


    # Test the Scroll to Top button.
    def test_15_scroll_top_btn(self):

        # Scroll down the web page
        self.driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")
        time.sleep(3)

        # test the scroll up button
        self.driver.find_element(By.ID, 'toTopHover').click()
        time.sleep(5)


    # Halt the webdriver and close the browser.
    def tearDown(self):
        self.driver.close()
        print("Test Completed!")

if __name__ == "__main__":
    unittest.main(testRunner=HtmlTestRunner.HTMLTestRunner(output='Test_Report', report_title='The Sparks Foundation Test Report', report_name='the_sparks_foundation'))