module hangman;
import <algorithm>;

Hangman::Hangman(std::string &word): word{word} {
	std::string g(word.length(), '#');
	guess = g;
}

int Hangman::guessLetter(const char c) {
	if (find(guesses.begin(), guesses.end(), c) != guesses.end()) return -1;	// already guessed letter
	
	bool status = false;
	for (int i = 0; i < static_cast<int>(word.length()); ++i) {
		if (word[i] == c) {
			guess[i] = c;
			status = true;
		}
	}
	guesses.emplace_back(c);
	if (status) {
		if (word == guess) return 2;
		return 1;
	}
	++wrongs;
	if (wrongs == 7) return -2;
	return 0;
}

int Hangman::getWrongs() {
	return wrongs;
}

std::string Hangman::getGuess() {
	return guess;
}

std::vector<char> Hangman::getGuesses() {
	return guesses;
}
