export module hangman;
import <string>;
import <vector>;

export class Hangman {
	const std::string word;
	std::string guess;
	int wrongs;
	std::vector<char> guesses;
public:
	Hangman(std::string &word);

	// returns -2 if the game is lost, -1 if letter already guessed, 0 if letter not in word,
	//  1 if it is in the word, and 2 if the player won (guess == word)
	//  updates the guess accordingly.
	int guessLetter(const char c);

	int getWrongs();
	std::string getGuess();
	std::vector<char> getGuesses();

};
