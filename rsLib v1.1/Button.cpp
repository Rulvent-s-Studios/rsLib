#include "Button.h"

void rsLib::Button::createButton(sf::Vector2f pos, sf::Vector2f size, sf::Color hovering, sf::Color pressed, sf::Color regular)
{
	button.setSize(size);
	button.setPosition(pos);
	button.setFillColor(regular);
	this->hovering = hovering;
	this->pressed = pressed;
	this->regular = regular;

}

void rsLib::Button::run(rsLib::CreateWindow& window)
{
	if (button.getGlobalBounds().contains(window.window.mapPixelToCoords(sf::Touch::getPosition(0) ))) {
		if (sf::Touch::isDown(0)) {
			pressedLeft = true;
		}
		else {
			pressedLeft = false;

		}
		ishovering = true;
	}
	else {
		ishovering = false;
	}

	if (button.getGlobalBounds().contains(window.window.mapPixelToCoords(sf::Mouse::getPosition(window.window)))) {
		button.setFillColor(hovering);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			pressedLeft = true;
			button.setFillColor(pressed);

		}
		else {
			pressedLeft = false;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			pressedRight = true;
			button.setFillColor(pressed);
		}
		else {
			pressedRight = false;
		}
		ishovering = true;
	}
	else {
		button.setFillColor(regular);

		ishovering = false;
		non_selected = false;
	}
}

void rsLib::Button::draw(rsLib::CreateWindow& window)
{
	window.draw(button);
}
