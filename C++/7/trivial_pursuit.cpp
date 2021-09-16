/*
 * Name: Frank Gomes
 * Lab: 7.0 Files
 * Date: 29-01-20
 * Extra: no
 */

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	// Create ifstream for answers file
	ifstream answers;
	answers.open("answers", ios::in);
	// Check if answers file could not be found and quit
	if (!answers) {
		cout << "The answers file could not be found." << endl;
		return 2;
	}
	// Create ofstream for players file
	ofstream players;
	players.open("players", ios::out);
	if (!players) {
		cout << "The players file could not be opened." << endl;
		return 13;
	}
	// Loop that terminates when there is no next player
	while (true) {
		// Get user's name
		cout << "Welcome to Trivial Pursuit™. Enter your name." << endl;
		string playerName;
		getline(cin, playerName);
		players << "Player: " << playerName << endl;
		// Track which question user is on
		int questionNumber = 1;
		// Input buffer
		string input;
		// Amount of questions user has gotten right & wrong
		int rightAnswers = 0, wrongAnswers = 0;
		// While there's another question, get and ask each question
		while (answers.peek() != EOF) {
			// Turn line into vector of values
			string line;
			getline(answers, line);
			vector<string> question;
			// Go through line and split at every '|'
			stringstream lineStream (line);
			string item;
			while (getline(lineStream, item, '|'))
				question.push_back(item);
			// Prompt user with question
			cout << question.at(1) << endl;
			// Print all answers
			for (int i = 2; i < question.size() - 1; i++)
				cout << (char) ('_' + i) << ". " << question.at(i) << endl;
			// Flag set to false when question is answered
			bool questionUnanswered = true;
			// Get user's response
			while (questionUnanswered) {
				getline(cin, input);
				switch (tolower(input[0])) {
					case 't':
					case 'a':
						if (question[question.size() - 1] == "a")
							rightAnswers++;
						else
							wrongAnswers++;
						questionUnanswered = false;
						break;
					case 'f':
					case 'b':
						if (question[question.size() - 1] == "b")
							rightAnswers++;
						else
							wrongAnswers++;
						questionUnanswered = false;
						break;
					case 'c':
						if (stoi(question.at(0)) < 3) {
							cout << "That was not a recognized answer. Try again." << endl;
							break;
						}
						if (question[question.size() - 1] == "c")
							rightAnswers++;
						else
							wrongAnswers++;
						questionUnanswered = false;
						break;
					case 'd':
						if (stoi(question.at(0)) < 4) {
							cout << "That was not a recognized answer. Try again." << endl;
							break;
						}
						if (question[question.size() - 1] == "d")
							rightAnswers++;
						else
							wrongAnswers++;
						questionUnanswered = false;
						break;
					default:
						cout << "That was not a recognized answer. Try again." << endl;
						break;
				}
			}
			// Reset questionUnanswered flag
			questionUnanswered = true;
			// Mark user's answer and correct answer
			players << "Q" << questionNumber << ": " << (char) tolower(input[0]) << " | Correct: " << question.at(question.size() - 1) << endl;
			// Increase question counter
			questionNumber++;
		}
		// Add final score to players file
		players << "Score: " << rightAnswers << "/" << rightAnswers + wrongAnswers << " correct" << endl;
		players << "------" << endl;
		// Ask user if another person wants to play
		cout << "Do you want to play again? (y/n)" << endl;
		getline(cin, input);
		if (tolower(input[0]) == 'y') {
			// Rewind back to beginning of tape...err, file
			answers.clear();
			answers.seekg(0, ios::beg);
			continue;
		}
		else if (tolower(input[0]) == 'n')
			break;
		else {
			cout << "Input not recognized. Quitting..." << endl;
			break;
		}
	}
	// Close the answers file and write mode players file
	answers.close();
	players.close();
	// Read out of answers file back to user
	answers.open("players", ios::in);
	string line;
	while (answers.peek() != EOF) {
		getline(answers, line);
		cout << line << endl;
	}
	// Quit gracefully
	cout << "Goodbye!" << endl;
	return 0;
}
