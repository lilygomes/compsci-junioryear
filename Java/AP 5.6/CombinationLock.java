/*
 * Frank Gomes
 * 04-05-2021
 * CodeHS AP 5.6 Lab
 * Extra: char[] constructor
 */

public class CombinationLock {
	private char[] combo = new char[4];

	/**
	 * Create new CombinationLock.
	 * @param combination The 4-character combination to use
	 * @throws IllegalArgumentException The combination is shorter than or longer than 4 digits
	 */
	public CombinationLock(String combination) throws IllegalArgumentException {
		if (combination.length() != 4)
			throw new IllegalArgumentException("Combination too long");
		else {
			combo[0] = combination.toLowerCase().charAt(0);
			combo[1] = combination.toLowerCase().charAt(1);
			combo[2] = combination.toLowerCase().charAt(2);
			combo[3] = combination.toLowerCase().charAt(3);
		}
	}

	/**
	 * Create new CombinationLock.
	 * @param combination The 4-character combination to use.
	 */
	public CombinationLock(char[] combination) {
		combo[0] = combination[0];
		combo[1] = combination[1];
		combo[2] = combination[2];
		combo[3] = combination[3];
	}

	/**
	 * Return clue for a guess of the combination.
	 * @param guess The 4-character string to guess the combination
	 * @throws IllegalArgumentException The combination is shorter than or longer than 4 digits
	 * @return A clue for the combination following the specified format.
	 */
	public String getClue(String guess) throws IllegalArgumentException {
		if (guess.length() != 4)
			throw new IllegalArgumentException("Combination too long");
		else {
			String clue = "";
			for (int i = 0; i < 4; i++) {
				// Perfect match
				if (guess.charAt(i) == combo[i])
					clue += combo[i];
				// Check to see if given character is somewhere in the combination
				else {
					// Character at position i is somewhere in the combination
					if (guess.charAt(i) == combo[0] || guess.charAt(i) == combo[1] ||
							guess.charAt(i) == combo[2] || guess.charAt(i) == combo[3])
						clue += "+";
					// Character at position i is not in the combination at all
					else
						clue += "*";
				}
			}
			return clue;
		}
	}

	/**
	 * Return clue for a guess of the combination.
	 * @param guess The 4-character array to guess the combination
	 * @return A clue for the combination following the specified format.
	 */
	public String getClue(char[] guess) {
		String clue = "";
		for (int i = 0; i < 4; i++) {
			// Perfect match
			if (guess[i] == combo[i])
				clue += combo[i];
			// Check to see if given character is somewhere in the combination
			else {
				// Character at position i is somewhere in the combination
				if (guess[i] == combo[0] || guess[i] == combo[1] ||
						guess[i] == combo[2] || guess[i] == combo[3])
					clue += "+";
				// Character at position i is not in the combination at all
				else
					clue += "*";
			}
		}
		return clue;
	}
}
