/*
 * Name: Frank Gomes
 * Date: 05-01-20
 * Lab: 4.0
 * Extra: Hashed password
 */

#include <iostream>
#include <iomanip>

using namespace std;

// Constants you can change later
const string THEATRE_NAME = "AMC New Vegas 24";
const int MAX_USERS = 1000;

int main() {
	// User attributes that get rewritten on every loop
	string user_name;
	string user_choice;
	string items;
	double total_price;
	bool cancel_order;
	// Set double precision for printing later
	cout.precision(2);
	// Keep greeting customers and taking orders until max user count is reached
	for (int customer = 999; customer <= MAX_USERS; customer++) {
		// Clear total price from last transaction
		total_price = 0.00;
		// Clear cancel_order flag in case previous order was invalidated
		cancel_order = false;
		// Clear items string of previous items in checkout
		items = "";
		// Print welcome message
		cout << "Welcome to " << THEATRE_NAME << "! Please enter your full name." << endl;
		// Get user's name
		getline(cin, user_name);
		// while loop that breaks when a successful transaction has gone through
		while (true) {
			// Show order menu
			cout << setw(15) << left << "(B)orgar" << "$4.25" << endl;	
			cout << setw(15) << left << "(F)rench Fried" << "$3.10" << endl;
			cout << setw(15) << left << "(S)osig" << "$6.90" << endl;
			cout << setw(15) << left << "B(e)ans" << "$9.99" << endl;
			cout << setw(15) << left << "(C)hease" << "$0.03" << endl;
			cout << "Enter the letter in parenthesis for your choice." << endl;
			// Get user's choice
			getline(cin, user_choice);
			// Add price of item selected to total price to charge to user
			switch (toupper(user_choice[0])) {
				case 'B':
					total_price += 4.25;
					items.append(" Borgar");
					break;
				case 'F':
					total_price += 3.10;
					items.append(" French Fried");
					break;
				case 'S':
					total_price += 6.90;
					items.append(" Sosig");
					break;
				case 'E':
					total_price += 9.99;
					items.append(" Beans");
					break;
				case 'C':
					total_price += 0.03;
					items.append(" Chease");
					break;
				case 'Q':
					cout << "Enter the passphrase. If you do not know what this is, input anything and press Enter." << endl;
					getline(cin, user_choice);
					// Plaintext passwords? Do you take me for an amateur?
					// Password: ShutMeDown!
					if (hash<string>{}(user_choice) == 15073409227018542674) {
						cout << "PLEASE USE NEXT MACHINE" << endl << "SERVICE CODE 0101" << endl;
						return 101;
					}
					else
						cancel_order = true;
					break;
				default:
					cout << "That is not a valid menu item. I'll assume you are not hungry." << endl << "Would you like to try again? (yes/no)" << endl;
					getline(cin, user_choice);
					// If user answers N or No, invalidate order and move onto next customer
					if (tolower(user_choice[0]) == 'n') {
						cout << "Next customer, please." << endl;
						cancel_order = true;
					}
					// If user answers Y or Yes, go back to food selection menu
					else if (tolower(user_choice[0]) == 'y')
						continue;
					// Interpret any inputs other than yes or no as no
					else {
						cout << "Input not recognized. I'll take that as a no." << endl << "Next customer, please." << endl;
						cancel_order = true;
					}
					break;
			}
			// If cancel_order flag is true, invalidate the order and go to the next iteration without serving anything to the customer
			if (cancel_order)
				break;
			// Ask if user wants to purchase another item
			cout << "Would you like another item? (yes/no)" << endl;
			getline(cin, user_choice);
			// If so, loop back to the item choice menu
			if (tolower(user_choice[0]) == 'y') {
				items.append(",");
				continue;
			}
			// If not, go to serving screen
			else if (tolower(user_choice[0]) == 'n')
				cout << "------------" << endl;
			// If neither yes or no, interpret input as no
			else
				cout << "Input not recognized. I'll take that as a no." << endl << "------------" << endl;
			// Print items user entered and final price
			cout << "Now preparing your" << items << "." << endl;
			cout << "Please insert $" << fixed << total_price << " to recieve your order." << endl;
			cout << "Enjoy the movie!" << endl << "-------------------" << endl;
			// Break while loop now that transaction is finished
			break;
		}
	}
	// After for loop terminates, go through natural shutdown procedure
	cout << "PLEASE USE NEXT MACHINE" << endl << "SERVICE CODE 0001" << endl;
	// Quit gracefully upon unit shutdown
	return 0;
}
