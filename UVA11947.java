import java.util.GregorianCalendar;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
	// write your code here
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        int future, day, month, year;
        for (int i = 1; i <= n; i++) {
            String s = sc.nextLine();
            day = Integer.parseInt(s.substring(2, 4));
            month = Integer.parseInt(s.substring(0, 2)) - 1;
            year = Integer.parseInt(s.substring(4));

            future = 40 * 7;
            GregorianCalendar cal = new GregorianCalendar(year, month, day);
            cal.add(GregorianCalendar.DAY_OF_MONTH, future);
            String sign = getSign(cal);
            System.out.println(String.format("%d %02d/%02d/%04d %s",i, (cal.get(GregorianCalendar.MONTH) + 1), cal.get(GregorianCalendar.DAY_OF_MONTH), cal.get(GregorianCalendar.YEAR), sign));
        }
    }

    private static String getSign(GregorianCalendar cal) {
        int year = cal.get(GregorianCalendar.YEAR);
        if (cal.compareTo(new GregorianCalendar(year, 0, 21)) >= 0 && cal.compareTo(new GregorianCalendar(year, 1, 19)) <= 0) {
            return "aquarius";
        } else if (cal.compareTo(new GregorianCalendar(year, 1, 20)) >= 0 && cal.compareTo(new GregorianCalendar(year, 2, 20)) <= 0) {
            return "pisces";
        } else if (cal.compareTo(new GregorianCalendar(year, 2, 21)) >= 0 && cal.compareTo(new GregorianCalendar(year, 3, 20)) <= 0) {
            return "aries";
        } else if (cal.compareTo(new GregorianCalendar(year, 3, 21)) >= 0 && cal.compareTo(new GregorianCalendar(year, 4, 21)) <= 0) {
            return "taurus";
        } else if (cal.compareTo(new GregorianCalendar(year, 4, 22)) >= 0 && cal.compareTo(new GregorianCalendar(year, 5, 21)) <= 0) {
            return "gemini";
        } else if (cal.compareTo(new GregorianCalendar(year, 5, 22)) >= 0 && cal.compareTo(new GregorianCalendar(year, 6, 22)) <= 0) {
            return "cancer";
        } else if (cal.compareTo(new GregorianCalendar(year, 6, 23)) >= 0 && cal.compareTo(new GregorianCalendar(year, 7, 21)) <= 0) {
            return "leo";
        } else if (cal.compareTo(new GregorianCalendar(year, 7, 22)) >= 0 && cal.compareTo(new GregorianCalendar(year, 8, 23)) <= 0) {
            return "virgo";
        } else if (cal.compareTo(new GregorianCalendar(year, 8, 24)) >= 0 && cal.compareTo(new GregorianCalendar(year, 9, 23)) <= 0) {
            return "libra";
        } else if (cal.compareTo(new GregorianCalendar(year, 9, 24)) >= 0 && cal.compareTo(new GregorianCalendar(year, 10, 22)) <= 0) {
            return "scorpio";
        } else if (cal.compareTo(new GregorianCalendar(year, 10, 23)) >= 0 && cal.compareTo(new GregorianCalendar(year, 11, 22)) <= 0) {
            return "sagittarius";
        } else if (cal.compareTo(new GregorianCalendar(year - 1, 11, 23)) >= 0 && cal.compareTo(new GregorianCalendar(year, 0, 20)) <= 0) {
            return "capricorn";
        } else if (cal.compareTo(new GregorianCalendar(year, 11, 23)) >= 0 && cal.compareTo(new GregorianCalendar(year + 1, 0, 20)) <= 0) {
                return "capricorn";
        } else {
            return "oops";
        }
    }
}
