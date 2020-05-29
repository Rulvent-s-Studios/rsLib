#pragma once
#include "SFML/Graphics.hpp"
#include "flags.h"
namespace rsLib {
	class Action {
	public:
 
		void setSettings(sf::Keyboard::Key up , sf::Keyboard::Key down , sf::Keyboard::Key left , sf::Keyboard::Key right);
 		void move(sf::RectangleShape& transform , float delta , actions action , float speed  = 0.9f, float drag = 0.5f, float maxVelocity = 14.f, float mutiplier = 60.f);
		sf::Vector2f position;
		bool pup = false;
		bool pdown = false;
		bool pleft = false;
		bool pright = false;
	private:
		sf::Vector2f currentVelocity;
		sf::Keyboard::Key up = sf::Keyboard::Unknown;
		sf::Keyboard::Key down = sf::Keyboard::Unknown;
		sf::Keyboard::Key left = sf::Keyboard::Unknown;
		sf::Keyboard::Key right = sf::Keyboard::Unknown;
		actions action = actions::NO_ACTION;
	
	 };
}

