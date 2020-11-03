from datetime import datetime, timedelta
from dateutil.relativedelta import relativedelta

if __name__ == "__main__":
    monthstep = relativedelta(months=1)
    count = 0

    date = datetime(1901, 1, 1)
    while date < datetime(2000, 12, 31):
        date += monthstep

        if date.weekday() == 6:
            count += 1

    print(count)


