import calendar


# Create a plain calender
c = calendar.TextCalendar(calendar.SUNDAY)
st = c.formatmonth(2023, 10, 0, 0)
print(st)

# Create a HTML formatted calender

hc = calendar.HTMLCalendar(calendar.SUNDAY)
st = hc.formatmonth(2023, 10)
print(st)

# loop over the days over a month
# zeros indicates that the day of the week is in an overlapping month
for i in c.itermonthdays(2023, 10):
    print(i)

for day in calendar.month_name:
    print(day)

print("team meeting will be on: ")
for m in range(1, 13):
    cal = calendar.monthcalendar(2023, m)
    weekone = cal[0]
    weektwo = cal[1]
    if weekone[calendar.FRIDAY] != 0:
        meetday = weekone[calendar.FRIDAY]
    else:
        meetday = weektwo[calendar.FRIDAY]

    print("%10s %2d" % (calendar.month_name[m], meetday))



'''
# The Output Part


October 2023
Su Mo Tu We Th Fr Sa
 1  2  3  4  5  6  7
 8  9 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28
29 30 31

<table border="0" cellpadding="0" cellspacing="0" class="month">
<tr><th colspan="7" class="month">October 2023</th></tr>
<tr><th class="sun">Sun</th><th class="mon">Mon</th><th class="tue">Tue</th><th class="wed">Wed</th><th class="thu">Thu</th><th class="fri">Fri</th><th class="sat">Sat</th></tr>
<tr><td class="sun">1</td><td class="mon">2</td><td class="tue">3</td><td class="wed">4</td><td class="thu">5</td><td class="fri">6</td><td class="sat">7</td></tr>
<tr><td class="sun">8</td><td class="mon">9</td><td class="tue">10</td><td class="wed">11</td><td class="thu">12</td><td class="fri">13</td><td class="sat">14</td></tr>
<tr><td class="sun">15</td><td class="mon">16</td><td class="tue">17</td><td class="wed">18</td><td class="thu">19</td><td class="fri">20</td><td class="sat">21</td></tr>
<tr><td class="sun">22</td><td class="mon">23</td><td class="tue">24</td><td class="wed">25</td><td class="thu">26</td><td class="fri">27</td><td class="sat">28</td></tr>
<tr><td class="sun">29</td><td class="mon">30</td><td class="tue">31</td><td class="noday">&nbsp;</td><td class="noday">&nbsp;</td><td class="noday">&nbsp;</td><td class="noday">&nbsp;</td></tr>
</table>

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
0
0
0
0

January
February
March
April
May
June
July
August
September
October
November
December
team meeting will be on: 
   January  6
  February  3
     March  3
     April  7
       May  5
      June  2
      July  7
    August  4
 September  1
   October  6
  November  3
  December  1

'''