import java.io.IOException;
import java.io.File;
import java.util.Scanner;
import java.util.ArrayList;

/**
 * A coin with a monetary value.
 */
public class Coin {
	/**
	 * Value of the coin.
	 */
	private double value;
	/**
	 * Name of the coin.
	 */
	private String name;
	/**
	 * Constructs a default coin.
	 */
	public Coin() {
		value = 0;
		name = "";
	}
	/**
	 * Constructs a default coin.
	 * @param coinValue Monetary value of the coin
	 * @param coinName Monetary name of the coin
	 */
	public Coin(double coinValue, String coinName) {
		value = coinValue;
		name = coinName;
	}
	/**
	 * Get value of the coin.
	 */
	public double getValue() {
		return value;
	}
	/**
	 * Get name of coin.
	 */
	public String getName() {
		return name;
	}
	/*--------------------- Static methods ---------------------*/
	/**
	 * Read coin value and name and return a coin.
	 * @param in Scanner for parsing values from.
	 */
	/* Turns out I don't have to implement this at all!
	 * There were pretty much no instructions, and skipping this works with the customer code just fine.
	public static Coin read(Scanner in) throws IOException {
		
	}
	*/
	/**
	 * Read a file with coin values and return an ArrayList of coins.
	 * @param String Name of file to read.
	 */
	public static ArrayList<Coin> readFile(String filename) throws IOException {
		// TODO
		// Create Scanner to read file.
		// Expected format: [name],[value]\n
		Scanner file = new Scanner(new File(filename));
		// List of coins.
		ArrayList<Coin> coins = new ArrayList<Coin>();
	}
}
