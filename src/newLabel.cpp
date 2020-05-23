#include "newLabel.h"
 
void rsLib::newLabel::createLabel(std::string font, std::string text, sf::Vector2f pos, int size, sf::Color color)
{
	this->font.loadFromFile(font);
	this->text.setFont(this->font);
	this->text.setCharacterSize(size);
	this->text.setString(text);
	this->text.setFillColor(color);
	this->text.setPosition(pos);
	this->stText = text;
}

 

void rsLib::newLabel::draw(CreateWindow& window)
{
	window.draw(text);
}

void rsLib::newLabel::setString(std::string text)
{
	this->text.setString(text);

}
