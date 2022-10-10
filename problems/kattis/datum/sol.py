#! /usr/bin/python3
from datetime import datetime

if __name__ == "__main__":
    day, month = map(int, input().split())

    dt = datetime(2009, month, day)
    wd = dt.weekday()
    weekdays = [
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday",
    ]
    print(weekdays[wd])
