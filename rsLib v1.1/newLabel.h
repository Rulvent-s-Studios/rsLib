#pragma once
#include <SFML/Graphics.hpp>
#include "CreateWindow.h"
#include "flags.h"
namespace rsLib {
	class newLabel
	{
	public:
		void createLabel(std::string font,  std::string text = "label", sf::Vector2f pos = sf::Vector2f(0, 0), int size = 30.0f, sf::Color color = sf::Color(255, 255, 255)    );
 		
		void draw(CreateWindow& window);
		void setString(std::string text);
	private:
		sf::Font font;
		sf::Text text;
		std::string stText;

	};

};