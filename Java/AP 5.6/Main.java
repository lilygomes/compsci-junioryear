/*
 * Frank Gomes
 * 04-05-2021
 * CodeHS AP 5.6 Lab
 * Extra: char[] constructor
 */

public class Main {
	public static void main(String[] args) {
		CombinationLock comboLock = new CombinationLock("frog");
		System.out.println(comboLock.getClue("oooo"));
		System.out.println(comboLock.getClue("flip"));
		System.out.println(comboLock.getClue("form"));
		System.out.println(comboLock.getClue("frag"));
		System.out.println(comboLock.getClue("frog"));
		char[] c = {'f', 'r', 'o', 'g'};
		CombinationLock comboLock2 = new CombinationLock(c);
		System.out.println(comboLock2.getClue("oooo"));
		System.out.println(comboLock2.getClue("flip"));
		System.out.println(comboLock2.getClue("form"));
		System.out.println(comboLock2.getClue("frag"));
		System.out.println(comboLock2.getClue("frog"));
	}
}
