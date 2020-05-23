#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "CreateWindow.h"
#include "flags.h"
 namespace rsLib {
	class LabelButton 
	{
	public:
		void createLabelButton( std::string font , std::string text,  sf::Vector2f pos, sf::Vector2f size, int textSize = 30 ,  sf::Color textColor = sf::Color(255, 255, 255), sf::Color hovering = sf::Color(48, 48, 48), sf::Color pressed = sf::Color(70, 70, 70), sf::Color regular = sf::Color(28, 28, 28));
		void run(rsLib::CreateWindow& window);
		void draw(rsLib::CreateWindow& window);
		void updateTextPos();
		void changeString(std::string text);
		bool pressedLeft = false;
		bool pressedRight = false;
		bool ishovering = false;
		bool non_selected = false;
		sf::RectangleShape button;
	private:
		sf::Font ffont;
		sf::Color hovering;
		sf::Color pressed;
		sf::Color regular;
		sf::Text text;
	};

}