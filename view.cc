export module view;
import hangman;
import <iostream>;

export class View {
	std::ostream &out;
public:
	View(std::ostream &out);
	void printView(Hangman &h);
};
