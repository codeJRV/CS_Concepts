
"""
For running on Linux machine,
change

import requests
import urllib.request as urllib2

to

import urllib2
"""

# https://www.glassdoor.com/Interview/Quora-Inc-Software-Engineer-Interview-Questions-EI_IE646885.0,9_KO10,27.htm
# https://www.glassdoor.com/Interview/Quora-Inc-Software-Engineer-Interview-Questions-EI_IE646885.0,9_KO10,27_IP2.htm


import urllib2
from lxml import html
from bs4 import BeautifulSoup
import json
import pprint
from datetime import datetime

pp = pprint.PrettyPrinter()

#Globals
RECENT = 0
PAST = 1
base = 'https://www.glassdoor.com/'
quora_internship_page_link = 'Interview/Quora-Inc-Software-Engineer-Interview-Questions-EI_IE646885.0,9_KO10,27.htm'
google_internship_page_link_1 = 'Interview/Google-Interview-Questions-E9079.htm?filter.jobTitleExact=Software+Engineer%28Internship%29'
google_internship_page_link_2 = 'Interview/Google-Software-Engineering-Intern-Interview-Questions-EI_IE9079.0,6_KO7,34.htm'
google_internship_page_link_3 = 'Interview/Google-Software-Engineer-Intern-Interview-Questions-EI_IE9079.0,6_KO7,31.htm'
google_internship_page_link_4 = 'Interview/Google-Intern-Interview-Questions-EI_IE9079.0,6_KO7,13.htm'

google_fulltime_links_1 = 'Interview/Google-Software-Engineer-Interview-Questions-EI_IE9079.0,6_KO7,24.htm'
google_fulltime_links_2 = 'Interview/Google-Software-Engineering-Interview-Questions-EI_IE9079.0,6_KO7,27.htm'
google_fulltime_links_3 = 'Interview/Google-Senior-Software-Engineer-Interview-Questions-EI_IE9079.0,6_KO7,31.htm'

facebook_internship_page_link_1 = 'Interview/Facebook-Intern-Interview-Questions-EI_IE40772.0,8_KO9,15.htm'
facebook_internship_page_link_2 = 'Interview/Facebook-Interview-Questions-E40772.htm?filter.jobTitleExact=Software+Engineer%28Internship%29'
facebook_internship_page_link_3 = 'Interview/Facebook-Software-Engineer-Intern-Interview-Questions-EI_IE40772.0,8_KO9,33.htm'
facebook_internship_page_link_4 = 'Interview/Facebook-Software-Engineering-Intern-Interview-Questions-EI_IE40772.0,8_KO9,36.htm'

liveramp_internship_page_link_1 = 'Interview/LiveRamp-Software-Engineer-Intern-Interview-Questions-EI_IE633892.0,8_KO9,33.htm'
liveramp_internship_page_link_2 = 'Interview/LiveRamp-Software-Engineering-Intern-Interview-Questions-EI_IE633892.0,8_KO9,36.htm'
liveramp_internship_page_link_3 = 'Interview/LiveRamp-Interview-Questions-E633892.htm?filter.jobTitleExact=Intern+-+Monthly'
liveramp_internship_page_link_4 = 'Interview/LiveRamp-Internship-Interview-Questions-EI_IE633892.0,8_KO9,19.htm'
liveramp_internship_page_link_5 = 'Interview/LiveRamp-Intern-Interview-Questions-EI_IE633892.0,8_KO9,15.htm'
liveramp_internship_page_link_6 = 'Interview/LiveRamp-Software-Internship-Interview-Questions-EI_IE633892.0,8_KO9,28.htm'
liveramp_internship_page_link_7 = 'Interview/LiveRamp-Software-Intern-Interview-Questions-EI_IE633892.0,8_KO9,24.htm'
liveramp_internship_page_link_8 = 'Interview/LiveRamp-Summer-Intern-Interview-Questions-EI_IE633892.0,8_KO9,22.htm'

nvidia_internship_page_link_1 = 'Interview/NVIDIA-Software-Intern-Interview-Questions-EI_IE7633.0,6_KO7,22.htm'
nvidia_internship_page_link_2 = 'Interview/NVIDIA-Software-Engineering-Intern-Interview-Questions-EI_IE7633.0,6_KO7,34.htm'
nvidia_internship_page_link_3 = 'Interview/NVIDIA-Interview-Questions-E7633.htm?filter.jobTitleExact=Software+Engineer%28Internship%29'
nvidia_internship_page_link_4 = 'Interview/NVIDIA-Software-Engineer-Intern-Interview-Questions-EI_IE7633.0,6_KO7,31.htm'
nvidia_internship_page_link_5 = 'Interview/NVIDIA-Intern-Interview-Questions-EI_IE7633.0,6_KO7,13.htm'

nvidia_fulltime_page_link_1 = 'Interview/NVIDIA-Software-Engineer-Interview-Questions-EI_IE7633.0,6_KO7,24.htm'
nvidia_fulltime_page_link_2 = 'Interview/NVIDIA-Systems-Engineer-Interview-Questions-EI_IE7633.0,6_KO7,23.htm'
nvidia_fulltime_page_link_3 = 'Interview/NVIDIA-Engineering-Interview-Questions-EI_IE7633.0,6_KO7,18.htm'
nvidia_fulltime_page_link_4 = 'Interview/NVIDIA-Software-Developer-Interview-Questions-EI_IE7633.0,6_KO7,25.htm'
nvidia_fulltime_page_link_5 = 'Interview/NVIDIA-Software-Engineering-Interview-Questions-EI_IE7633.0,6_KO7,27.htm'

fidessa_all_page_link = 'Interview/Fidessa-Interview-Questions-E11915.htm'
nvidia_all_page_link = 'Interview/NVIDIA-Interview-Questions-E7633.htm'
dell_all_page_link = 'Interview/Dell-Interview-Questions-E1327.htm'
dropbox_all_page_link = 'Interview/Dropbox-Interview-Questions-E415350.htm'
mathworks_all_page_link = 'Interview/MathWorks-Interview-Questions-E17117.htm'

liveramp_internship_links = [liveramp_internship_page_link_1, liveramp_internship_page_link_2, liveramp_internship_page_link_3, liveramp_internship_page_link_4, liveramp_internship_page_link_5, liveramp_internship_page_link_6, liveramp_internship_page_link_7, liveramp_internship_page_link_8]
facebook_internship_links = [facebook_internship_page_link_1, facebook_internship_page_link_2, facebook_internship_page_link_3, facebook_internship_page_link_4]
google_internship_links = [google_internship_page_link_1, google_internship_page_link_2, google_internship_page_link_3, google_internship_page_link_4]
google_fulltime_links = [google_fulltime_links_1, google_fulltime_links_2, google_fulltime_links_3]
nvidia_internship_links = [nvidia_internship_page_link_1, nvidia_internship_page_link_2, nvidia_internship_page_link_3, nvidia_internship_page_link_4, nvidia_internship_page_link_5]
nvidia_fulltime_links = [nvidia_fulltime_page_link_1, nvidia_fulltime_page_link_2, nvidia_fulltime_page_link_3, nvidia_fulltime_page_link_4, nvidia_fulltime_page_link_5]
fidessa_all_links = [fidessa_all_page_link]
nvidia_all_links = [nvidia_all_page_link]
dell_all_links = [dell_all_page_link]
dropbox_all_links = [dropbox_all_page_link]
mathworks_all_links = [mathworks_all_page_link]



####################################################

# $> python glassdoor.py >mathworks_intern_questions.doc 

###
page_links = mathworks_all_links
only_questions = True
only_intern = True

def GetPageSource(current_page):
    #print (base+current_page)
    
    hdr = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.64 Safari/537.11',
       'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
       'Accept-Charset': 'ISO-8859-1,utf-8;q=0.7,*;q=0.3',
       'Accept-Encoding': 'none',
       'Accept-Language': 'en-US,en;q=0.8',
       'Connection': 'keep-alive'}
    req = urllib2.Request(base+current_page, headers=hdr)
    page = urllib2.urlopen(req)
    
    soup = BeautifulSoup(page, "lxml")
    return soup
    '''
    with open('workfile', 'r') as f:
        soup = f.read()
    return BeautifulSoup(soup)
    '''

def SeparateInteviews(soup):
    lists = soup.find_all("li", class_="empReview")
    d = []
    for item in lists:
        t = {}
        try:
            date_ = str(item.find("time", class_="date subtle small").get_text()).strip()
        except:
            pass
        try:
            t['date'] = datetime.strptime(date_, "%b %d, %Y")
        except:
            t['date'] = datetime.strptime('Jan 01, 2015', "%b %d, %Y")
            pass
        try:
            t['title'] = str(item.find("span", class_="reviewer").get_text())
        except:
            pass
        try:
            t['offer'] = str(item.find_all("span", class_="middle")[0].get_text())
        except:
            pass
        try:
            t['application'] = str(item.find("p", class_="applicationDetails mainText truncateThis wrapToggleStr ").get_text())
        except:
            pass
        try:
            t['experience'] = str(item.find("p", class_="interviewDetails mainText truncateThis wrapToggleStr ").get_text())
        except:
            pass
        try:
            qs = item.find_all("span", class_="interviewQuestion noPadVert truncateThis wrapToggleStr ")
            tq = []
            for q in qs:
                tq.append(q.get_text().strip())
            t['questions'] = tq
        except:
            pass

        '''
        print t['title']
        print t['offer']
        print t['application']
        print t['questions']
        '''
        d.append(t)
    return d

def DifferentiateEachJob(jobs):
    list_of_jobs = []

def IsSoftDev(title):
    title = title.lower().replace(" ", "")
    keywords = ['software', 's/w', 'sw', 'engineer', 'develop']
    count = 0
    for keyword in keywords:
        if keyword in title:
            count += 1
    if count > 1:
        return True
    return False

def IsSoftwareIntern(title):
    title = title.lower().replace(" ", "")
    keywords = ['intern']
    count = 0
    for keyword in keywords:
        if keyword in title:
            count += 1
    if count > 0:
        return True
    return False

all_interviews = []

for page_link in page_links:
    current_page = page_link
    # print current_page

    while True:
        
        #print current_page
        soup = GetPageSource(current_page)
        lists = SeparateInteviews(soup)
        all_interviews.extend(lists)
        #print(len(lists))
        #pp.pprint(lists)
        next_ = soup.find("li", class_="next")#.get_text()
        #print(str(next_))
        string_next = str(next_)
        if 'disabled' in string_next:
            break
        try:
            current_page = next_.a["href"]
        except:
            break
        #break

    #print current_page

#pp.pprint(all_interviews)
all_interviews = sorted(all_interviews, key=lambda k:k['date'], reverse=True)

for interview in all_interviews:

    if IsSoftDev(interview['title']) and IsSoftwareIntern(interview['title']):
        try:
            print str(interview['date'].strftime('%b %d, %Y'))
        except:
            pass

        if not only_questions:
            print ""
            print ""

        try:
            print interview['title']
        except:
            pass

        try:
            print interview['offer']
        except:
            pass

        print ""

        if not only_questions:
            print ""
            print 'Application:'
            try:
                print interview['application']
                pass
            except:
                pass
            print ""
            print ""
            print 'Experience:'
            try:
                print interview['experience']
                pass
            except:
                pass
            print ""
            print ""

        print 'Questions:'

        try:
            for question in interview['questions']:
                print str(question.encode('utf-8'))
        except:
            pass
        print ""
        print ""
        print ""
        print ""
        if not only_questions:
            print "\f"
        #print current_page
            #li class='next'
    else:
        pass
#print soup
