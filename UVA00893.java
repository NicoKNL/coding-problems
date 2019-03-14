import java.util.GregorianCalendar;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
	// write your code here
        Scanner sc = new Scanner(System.in);
        int future, day, month, year;
        while (true) {
            String s = sc.nextLine();
            if (s.equals("0 0 0 0")) break;
            String[] split = s.split(" ");
            future = Integer.parseInt(split[0]);
            day = Integer.parseInt(split[1]);
            month = Integer.parseInt(split[2]) - 1;
            year = Integer.parseInt(split[3]);

            GregorianCalendar cal = new GregorianCalendar(year, month, day);
            cal.add(GregorianCalendar.DAY_OF_MONTH, future);
            System.out.println(cal.get(GregorianCalendar.DAY_OF_MONTH) + " " + (cal.get(GregorianCalendar.MONTH) + 1) + " " + cal.get(GregorianCalendar.YEAR));
        }
    }
}
