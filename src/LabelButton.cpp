#include "LabelButton.h"
void rsLib::LabelButton::createLabelButton( std::string font,  std::string text,sf::Vector2f pos, sf::Vector2f size, int textSize ,  sf::Color textColor, sf::Color hovering, sf::Color pressed, sf::Color regular)
{


	button.setSize(size);
	button.setPosition(pos);
	button.setFillColor(regular);
	this->hovering = hovering;
	this->pressed = pressed;
	this->regular = regular;
	this->text.setCharacterSize( textSize );

	ffont.loadFromFile(font);
	 
	this->text.setString(text);
	this->text.setFont(ffont);
	this->text.setFillColor(textColor);
	float xPos = (pos.x + button.getGlobalBounds().width / 2) - (this->text.getGlobalBounds().width / 2);
	float yPos = (pos.y + button.getGlobalBounds().height / 2) - (this->text.getGlobalBounds().height / 2);
	this->text.setPosition(sf::Vector2f(xPos, yPos));
 
}

void rsLib::LabelButton::run(rsLib::CreateWindow& window)
{
	if (button.getGlobalBounds().contains(window.window.mapPixelToCoords(sf::Touch::getPosition(0)))) {
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

void rsLib::LabelButton::draw(rsLib::CreateWindow& window)
{
	window.draw(button);
	window.draw(this->text);
}

void rsLib::LabelButton::updateTextPos()
{

	float xPos = (button.getPosition().x + button.getGlobalBounds().width / 2) - (this->text.getGlobalBounds().width / 2);
	float yPos = (button.getPosition().y + button.getGlobalBounds().height / 2) - (this->text.getGlobalBounds().height / 2);
	this->text.setPosition(sf::Vector2f(xPos, yPos));
}

void rsLib::LabelButton::changeString(std::string text)
{
	this->text.setString(text);
}
