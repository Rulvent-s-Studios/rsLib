#include "NewTextBox.h"

void rsLib::NewTextBox::createTextBox(std::string font, bool useLineSpace, int charSize, sf::Color color, bool useLimit, int textLimit, sf::Vector2f pos)
{

	this->useLineSpace = useLineSpace;

	this->font.loadFromFile(font);
	text.setFont(this->font);
	text.setCharacterSize(charSize);
	text.setFillColor(color);
	text.setPosition(
		pos

	);
	LimitActive = useLimit;
	this->limit = textLimit;
	sf::Keyboard::setVirtualKeyboardVisible(true);

}

void rsLib::NewTextBox::clearString()
{
	ttext.str("");
	text.setString("");
}

void rsLib::NewTextBox::EventText(sf::Event evnt) {

	if (evnt.type == evnt.TextEntered) {
		int charTyped = evnt.text.unicode;
		if (charTyped < 128) {
			if (LimitActive) {
				if (ttext.str().length() <= limit) {

					inputLogic(charTyped);
				}
				else {
					if (ttext.str().length() > limit) {

						if (charTyped == 8) {
							deleteLastCharacter();

						}
					}
				}
			}
			else  if (!LimitActive)
			{
				inputLogic(charTyped);

			}
		}
	}
}

std::string rsLib::NewTextBox::getText() {
	return ttext.str();

}

void rsLib::NewTextBox::inputLogic(int charTyped)
{
	if (charTyped != 8 && charTyped != 13) {

		ttext << static_cast<char>(charTyped);

	}
	else if (charTyped == 8) {

		if (ttext.str().length() != 0) {
			deleteLastCharacter();
		}
	}
	else if (charTyped == 13 && useLineSpace) {

		std::string t = ttext.str();
		std::string newT = "\n";


		ttext << newT;

	}
	text.setString(ttext.str() + cursor);
}

void rsLib::NewTextBox::deleteLastCharacter()
{
	std::string t = ttext.str();
	std::string newT = "";
	for (int i = 0; i < t.length() - 1; i++) {
		newT += t[i];
	}
	ttext.str("");
	ttext << newT;
	text.setString(ttext.str() + cursor);
}

void rsLib::NewTextBox::useTextBox(CreateWindow& windowContext) {
	windowContext.draw(text);

}