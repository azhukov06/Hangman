import hangman;
import view;
import <iostream>;
import <fstream>;
import <sstream>;
import <string>;
import <cstdlib>;

using namespace std;
int main(int argc, char *argv[]) {
	int x = 21137888;
	if (argc > 1) {
		string seed = argv[1];
		istringstream ss{seed};
		int y;
		if (ss >> y) x = y;
	}
	srand(x);

	while (true) {
		fstream f{"words.txt"};
		x = rand() % 10000;
		for (int i = 0; i < x; ++i) {
			string s;
			f >> s;
		}
		string word;
		f >> word;
		
		View v{cout};
		Hangman h{word};
		cout << "Let's play Hangman! Try guess the word!" << endl;
		v.printView(h);
		while (true) {
			char c;
			cout << "Please enter a letter: ";
			cin >> c;
			if (cin.eof()) {
				cout << endl;
				return 0;
			}
			if (!cin || !(('a' <= c) && (c <= 'z'))) {
				cout << endl << "Invalid input. ";
				cin.clear();
				cin.ignore();
				continue;
			}
			int result = h.guessLetter(c);
			cout << endl << endl;
			v.printView(h);
			if (result == -1) {
				cout << "Letter " << c << " has already been guessed." << endl;
				continue;
			}
			if (result == 0 || result == -2) {
				cout << "Letter " << c << " is not in the word." << endl;
				if (result == -2) {
					cout << "DEFEAT! The man was hanged. The word was: " << word << endl;
					break;
				}
			}
			if (result == 1 || result == 2) {
				cout << "Letter " << c << " is in the word." << endl;
				if (result == 2) {
					cout << "VICTORY! The word was: " << word << endl;
					break;
				}
			}

		}
		bool playAgain = false;
		while (true) {
			cout << "Would you like to play again? (y/n) ";
			char s;
			cin >> s;
			if (cin.eof()) return 0;
			if (!cin || (s != 'y' && s != 'n')) {
				cout << "Invalid input. ";
				continue;
			}
			playAgain = (s == 'y');
			break;
		}
		if (!playAgain) return 0;
	}
}
