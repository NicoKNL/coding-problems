from datetime import datetime, timedelta

colleagues = int(input())
dates = list()
for i in range(colleagues):
    line = input()
    name, datebase = line.split(" ")
    year = 2001
    month, day = datebase.split("-")
    dates.append(datetime(year=year, month =int(month), day =int(day)))

dates = sorted(dates)
tmpdate = dates[0]
dates.append(datetime(year = tmpdate.year+1, month = tmpdate.month, day = tmpdate.day))

max_dist = -1
base_dates = []
base_dist = None
for i in range(len(dates) - 1):
    dist = dates[i + 1] - dates[i]
    if dist.days > max_dist:
        max_dist = dist.days
        base_dates = [dates[i+1]]
        base_dist = dist
    elif dist.days == max_dist:
        base_dates.append(dates[i+1])
    else:
        pass

dist = 9999
october = datetime(year = 2000, month = 10, day = 29)
for d in base_dates:
    timedist = abs((d - october).days % 365)
    if (timedist < dist):
        base_date = d
        dist = timedist

mydate = base_date - timedelta(days=1)
myday = str(mydate.day).zfill(2)
mymonth = str(mydate.month).zfill(2)


print("{0}-{1}".format(mymonth, myday))

'''
3
Henk 01-09
Roos 09-20
Pietje 11-11

16
Henk 01-09
Luc 12-31
Jan 03-22
Roos 09-20
Pietje 11-11
Anne 02-28
P 09-25
D 12-15
L 11-17
C 05-01
L 08-02
M 04-25
M 06-12
J 03-26
M 01-20
J 01-20

3
J 04-29
J 10-28
J 04-28

3
C 04-30
C 10-29
C 04-29


# critical case!!!
8
H 12-01
H 02-01
H 04-01
H 06-01
H 08-01
H 10-01
H 07-01
H 01-01
'''