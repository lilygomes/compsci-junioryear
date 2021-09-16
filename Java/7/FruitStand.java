/*
 *  19-10-20
 *  Fruit Stand Lab
 *  Extra: Calculates total value of cart
 */
import java.util.ArrayList;
import java.util.Scanner;

public class FruitStand {
	public static void main(String[] args) {
		// Basket of fruits
		ArrayList<Fruit> basket = new ArrayList<Fruit>();
		// Scanner for keyboard input
		Scanner kbd = new Scanner(System.in);
		// Boolean that is toggled when shopper is done
		boolean finished = false;
		// While user is not finished, keep prompting for items
		while (!finished) {
			System.out.println("What fruit would you like?");
			// Store user input
			String fruitName = kbd.next();
			System.out.println("How many would you like?");
			int amount = kbd.nextInt();
			// Determine what fruit to use
			switch (fruitName.toLowerCase()) {
				case "apples":
				case "apple":
					basket.add(new Fruit(FruitTypes.APPLE, amount));
					break;
				case "oranges":
				case "orange":
					basket.add(new Fruit(FruitTypes.ORANGE, amount));
					break;
				case "bananas":
				case "banana":
					basket.add(new Fruit(FruitTypes.BANANA, amount));
					break;
				case "passionfruits":
				case "passionfruit":
					basket.add(new Fruit(FruitTypes.PASSIONFRUIT, amount));
					break;
				case "kiwis":
				case "kiwi":
					basket.add(new Fruit(FruitTypes.KIWI, amount));
					break;
				default:
					System.out.println("Sorry, we don't carry " + fruitName + " here.");
					break;
			}
			// Ask user if they would like to continue shopping
			System.out.println("Would you like to continue shopping? (y/n)");
			fruitName = kbd.next();
			// If response starts with n, go to checkout
			if (fruitName.toLowerCase().charAt(0) == 'n')
				break;
		}
		// Checkout
		// Total sum price
		float totalPrice = 0;
		for (Fruit f : basket) {
			// Print the name, count, and total price for each item
			System.out.printf("%14s%4d6.2f\n", f, f.toInt(), (f.toInt() * getPrice(f)));
			// When iterating over list, add to sum
			totalPrice += (f.toInt() * getPrice(f));
		}
		// Print total price
		System.out.printf("Total price: $%.2f\n", totalPrice);
		// Close user input scanner
		kbd.close();
	}

	// Method that returns proper price for each fruit
	private static float getPrice(Fruit f) {
		switch(f.getType()) {
			case APPLE:
				return 0.50f;
			case ORANGE:
				return 0.65f;
			case BANANA:
				return 0.36f;
			case PASSIONFRUIT:
				return 0.85f;
			case KIWI:
				return 0.70f;
			default:
				return 0.00f;
		}
	}
}
