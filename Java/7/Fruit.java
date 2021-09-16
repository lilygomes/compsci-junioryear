/*
 *  19-10-20
 *  Extra: Calculates total value of cart
 *  Fruit Stand Lab
 */

public class Fruit {
	// Type of fruit
	private final FruitTypes type;
	// Amount of fruit
	private int amount;

	/**
	 * Creates a new Fruit.
	 * @param type Type of fruit.
	 * @param amount Amount of fruit.
	 */
	public Fruit(FruitTypes type, int amount) {
		this.type = type;
		this.amount = amount;
	}

	/**
	 * Creates a new Fruit.
	 * @param type Type of fruit.
	 */
	public Fruit(FruitTypes type) {
		this(type, 1);
	}

	/**
	 * Return amount of fruit as int.
	 */
	public int toInt() {
		return this.amount;
	}

	/**
	 * Return type of fruit as a String.
	 */
	public String toString() {
		return this.type.toString();
	}

	/**
	 * Return type of fruit as FruitTypes.
	 */
	public FruitTypes getType() {
		return this.type;
	}
}
