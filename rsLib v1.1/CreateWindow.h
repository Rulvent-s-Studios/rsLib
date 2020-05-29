#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

namespace rsLib {
	class CreateWindow
	{
	public:
		void settings(sf::VideoMode vm, std::string winTitle, sf::Uint32 style = sf::Style::Default, sf::ContextSettings context = sf::ContextSettings());

		void useDefaultPolls();
		void clear();
		void clear(sf::Color color);
		void display();
		void draw(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);
		void setView(sf::View view);
		void cursorVisible(bool shown);
		/* Check */
		bool isOpen();
		bool pollevents();


		/* external: */
		void useDeltaTime();
		float deltaTime = 0.f;

		void setCursor(std::string src);
		void updateCursor();
		void drawCursor();
		/* some sf, data types*/
		sf::RenderWindow window;
		sf::Event event = sf::Event();
		sf::View fixed = window.getView();
		float getFps();
	private:
		sf::Clock clock;
		sf::Clock mClock;
		unsigned int frame = (unsigned int)0;
		unsigned int fps = (unsigned int)0;
		sf::Texture texture;
		sf::Sprite cursor;
	};

}