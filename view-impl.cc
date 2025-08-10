module view;
import <vector>;

View::View(std::ostream &out): out{out} {}

void View::printView(Hangman &h) {
	std::vector<char>guesses = h.getGuesses();
	int w = h.getWrongs();

	out << "------------------------------\n";
	out << "GUESSES: ";
	for (auto c:guesses) {
		out << c << " ";
	}
	out << "\n";
	out << "MAN STATUS:\n |\n";
	if (w > 0) out << " 0\n";
	if (w == 2) out << " |\n";
	if (w == 3) out << "/|\n";
	if (w >= 4) out << "/|\\\n";
	if (w > 4) out << " |\n";
	if (w == 6) out << "/\n";
	if (w == 7) out << "/ \\\n";
	out << "WORD: " << h.getGuess() << '\n';
	out << "------------------------------\n";
}
