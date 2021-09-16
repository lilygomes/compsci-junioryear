/*
 * Lab: 9.0 Project
 * Date: 10-04-20
 * Extra: Uses comma delimiters to allow first & last names with spaces in them
 */

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;

struct Donor {
	string FIRST_NAME, LAST_NAME;
	int TELEPHONE_NUMBER, DONATION;
};

int main() {
	// Read in donors from DonorList.txt in root of project
	fstream donor_list;
	donor_list.open("DonorList.txt", ios::in);
	if (!donor_list) {
		cout << "The donor file could not be opened." << endl;
		return 2;
	}
	// List of donors
	vector<Donor> donors;
	// While there are more lines in the donor_list, read in info and turn it into structs
	while (donor_list.peek() != EOF) {
		// Take name line and split on ", "
		vector<string> names;
		string name_line;
		getline(donor_list, name_line);
		boost::split(names, name_line, boost::is_any_of(", "));
		// Get phone number
		string phone_num;
		getline(donor_list, phone_num);
		// Get donation amount
		string donation_amt;
		getline(donor_list, donation_amt);
		// Create struct and push to back of vector
		donors.push_back(Donor{names[0], names[1], stoi(phone_num), stoi(donation_amt)});
	}
	return 0;
}
