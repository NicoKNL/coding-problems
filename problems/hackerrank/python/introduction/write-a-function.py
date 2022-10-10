def is_leap(year):
    leap = False

    div_by_four = (year % 4 == 0)
    div_by_hundred = (year % 100 == 0)
    div_by_four_hundred = (year % 400 == 0)

    if div_by_four:
        if div_by_hundred:
            if div_by_four_hundred:
                return True
            else:
                return False
        else:
            return True
    else:
        return False


if __name__ == "__main__":
    year = int(input())

    print(is_leap(year))