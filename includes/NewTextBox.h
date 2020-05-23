#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "CreateWindow.h"
#include <sstream>
#include <string>
namespace rsLib {
	class NewTextBox
	{
	public:

		void createTextBox(std::string font, bool useLineSpace = true, int charSize = 30, sf::Color color = sf::Color::White, bool useLimit = false, int textLimit = 100, sf::Vector2f pos = sf::Vector2f(0, 0));
		void useTextBox(CreateWindow& windowContext);
		void clearString();
		void EventText(sf::Event evnt);
		std::string getText();
		char cursor = '_';
	private:
		std::ostringstream ttext;
		bool useLineSpace = false;
		sf::Color _color;
		sf::Text text;
		sf::Font font;
		float x = 0.0f;
		float y = 0.0f;
		int limit = 0;
		bool LimitActive = false;
		void inputLogic(int charTyped);
		void deleteLastCharacter();
	};

}