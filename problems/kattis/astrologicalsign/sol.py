t = int(input())

MONTHS = [
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec",
]

SIGNS = {
    "Aries": ((21, "Mar"), (20, "Apr")),
    "Taurus": ((21, "Apr"), (20, "May")),
    "Gemini": ((21, "May"), (21, "Jun")),
    "Cancer": ((22, "Jun"), (22, "Jul")),
    "Leo": ((23, "Jul"), (22, "Aug")),
    "Virgo": ((23, "Aug"), (21, "Sep")),
    "Libra": ((22, "Sep"), (22, "Oct")),
    "Scorpio": ((23, "Oct"), (22, "Nov")),
    "Sagittarius": ((23, "Nov"), (21, "Dec")),
    "Capricorn": ((22, "Dec"), (20, "Jan")),
    "Aquarius": ((21, "Jan"), (19, "Feb")),
    "Pisces": ((20, "Feb"), (20, "Mar")),
}

for _ in range(t):
    day, month = input().split()
    day = int(day)

    for sign, ((start_day, start_month), (end_day, end_month)) in SIGNS.items():
        offset = (MONTHS.index(start_month) - MONTHS.index(month) + 12) % 12
        if offset == 0 or offset == 11:
            if month == start_month and day >= start_day:
                print(sign)
                break

            if month == end_month and day <= end_day:
                print(sign)
                break
