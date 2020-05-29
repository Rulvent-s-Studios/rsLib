#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "CreateWindow.h"
namespace rsLib {
	class Button
	{
	public:
		void createButton(sf::Vector2f pos, sf::Vector2f size, sf::Color hovering = sf::Color(48,48,48), sf::Color pressed = sf::Color(70,70,70), sf::Color regular = sf::Color(28,28,28));
		void run(rsLib::CreateWindow& window);
		void draw(rsLib::CreateWindow& window);

		bool pressedLeft = false;
		bool pressedRight = false;
		bool ishovering = false;
		bool non_selected = false;
		sf::RectangleShape button;
	private:
		sf::Color hovering;
		sf::Color pressed; 
		sf::Color regular;
	};
}

