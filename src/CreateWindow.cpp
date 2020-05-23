#include "CreateWindow.h"

void rsLib::CreateWindow::settings(sf::VideoMode vm, std::string winTitle, sf::Uint32 style, sf::ContextSettings context)
{
	window.create(vm, winTitle,style, context);
}

void rsLib::CreateWindow::useDefaultPolls()
{
	/* default pollevents: */
	if (event.type == sf::Event::Closed) {
		window.close();
	} 
}

void rsLib::CreateWindow::clear()
{
	window.clear();

}

void rsLib::CreateWindow::clear(sf::Color color)
{
	window.clear(color);
}

void rsLib::CreateWindow::display()
{
 
	window.display();
} 

void rsLib::CreateWindow::draw(const sf::Drawable& drawable, const sf::RenderStates& states)
{

	window.draw(drawable, states);
}

void rsLib::CreateWindow::setView(sf::View view)
{
	window.setView(view);
}

void rsLib::CreateWindow::cursorVisible(bool shown)
{
	window.setMouseCursorVisible(shown);
}

 

 
bool rsLib::CreateWindow::isOpen()
{
	return window.isOpen();
}

bool rsLib::CreateWindow::pollevents()
{
	return window.pollEvent(event);
}

void rsLib::CreateWindow::useDeltaTime()
{
	deltaTime = clock.restart().asSeconds();
}

void rsLib::CreateWindow::setCursor(std::string src)
{
	if (!this->texture.loadFromFile(src)) {
		std::cout << "failed to load: " << src << std::endl;
		exit(-1);
	}
	this->cursor.setTexture(texture);
	cursor.setOrigin(sf::Vector2f(cursor.getGlobalBounds().width / 2, cursor.getGlobalBounds().height / 2));
}

void rsLib::CreateWindow::updateCursor()
{
	 cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
	 
 	 
	}

void rsLib::CreateWindow::drawCursor()
{
	window.draw(cursor);
}

float rsLib::CreateWindow::getFps()
{
	if (mClock.getElapsedTime().asSeconds() >= 1.f)
	{
		fps = frame;
		frame = 0;
		mClock.restart();
	}

	++frame;
	return fps;
 }
