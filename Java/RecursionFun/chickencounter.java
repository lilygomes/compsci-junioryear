import java.util.Scanner;
class Main {
  public static void main(String[] args) {
	Scanner kbd = new Scanner(System.in);
		int num = kbd.nextInt();
		int sum = 0;
		while (num > 0) {
			if ((num % 10) % 2 == 1)
				sum += num % 10;
			num /= 10;
		}
		System.out.println(sum);
		kbd.close();
	}
}
